EXTENSION = wbase64        # the extensions name
DATA = wbase64--0.0.1.sql  # script files to install
OBJS = wbase64.o
# postgres build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)