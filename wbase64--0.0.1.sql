\echo Use "CREATE EXTENSION wbase64" to load this file. \quit
CREATE FUNCTION pgw_b64_encode(text) RETURNS text
AS 'MODULE_PATHNAME', 'pgw_b64_encode' 
LANGUAGE C IMMUTABLE STRICT;

-- CREATE FUNCTION pgw_b64_decode(dec TEXT) RETURNS TEXT
-- AS 'MODULE_PATHNAME', 'pgw_b64_decode' 
-- LANGUAGE C IMMUTABLE STRICT;