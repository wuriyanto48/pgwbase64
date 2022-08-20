EXTENSION = wbase64        # extensions name
DATA = wbase64--0.0.1.sql  # script
OBJS = wbase64.o
# build
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)