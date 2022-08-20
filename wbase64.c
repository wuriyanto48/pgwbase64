#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include "b64.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(pgw_b64_encode);
Datum
pgw_b64_encode(PG_FUNCTION_ARGS)
{
    text* t = PG_GETARG_TEXT_PP(0);
    if (t->length <= 0) 
    {
        ereport(ERROR,
            (errcode(STRING_DATA_LENGTH_MISTMATCH),
                errmsg("empty values are not allowed")
            )
        );
    }

    unsigned char* dst = NULL;
    size_t dst_size = 0;
    int encode_ok = encode_b64(input, 0, &dst, &dst_size);
    if (encode_ok != 0)
    {
        ereport(ERROR,
            (errcode(DATA_EXCEPTION),
                errmsg("error encode text to base64")
            )
        );
    }
}