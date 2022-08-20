#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include <string.h>
#include "b64.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(pgw_b64_encode);
Datum
pgw_b64_encode(PG_FUNCTION_ARGS)
{
    text* input_text = PG_GETARG_TEXT_PP(0);
    int32  text_size = VARSIZE_ANY_EXHDR(input_text);
    if (text_size <= 0) 
    {
        ereport(ERROR,
            (errcode(ERRCODE_STRING_DATA_LENGTH_MISMATCH),
                errmsg("empty values are not allowed")
            )
        );
    }

    char* input_text_cleaned = text_to_cstring(input_text);

    unsigned char* dst = NULL;
    size_t dst_size = 0;
    int encode_ok = encode_b64(input_text_cleaned, 0, &dst, &dst_size);
    if (encode_ok != 0)
    {
        ereport(ERROR,
            (errcode(ERRCODE_DATA_EXCEPTION),
                errmsg("error encode text to base64")
            )
        );
    }

    char* result = palloc(dst_size * sizeof(char));
    memcpy((void*) result, (void*) dst, dst_size);

    free((void*) dst);
    PG_RETURN_TEXT_P(cstring_to_text(result));
}