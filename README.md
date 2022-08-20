# wbase64

Base64 PostgreSQL Extension

## Getting started

### Building
Install PostgreSQL Development server and client
```shell
$ sudo apt install libpq-dev
$ sudo apt-get install -y postgresql-server-dev-10
```

Compile extensions, Create and Copy SHARED Library to `/usr/lib/postgresql/10/lib/`
```shell
$ cc -fPIC -c wbase64.c -I /usr/include/postgresql/10/server/
$ cc -shared -o wbase64.so wbase64.o
$ sudo cp wbase64.so  /usr/lib/postgresql/10/lib/
```

Install extensions
```shell
$ sudo make USE_PGXS=1 install
```

### Install to Database

Login as superuser
```shell
$ sudo --login --user postgres
$ psql
```

Connect to specific Database
```shell
$ \c database_name;
```

Show installed extensions
```shell
$ select extname from pg_extension;
```

Drop extensions
```shell
$ DROP EXTENSION IF EXISTS wbase64;
```

Create extensions
```shell
$ CREATE EXTENSION IF NOT EXISTS wbase64;
```

### Test the extensions

Encode
```shell
database_name=# select pgw_b64_encode('this is dark') as res;
       res
------------------
 dGhpcyBpcyBkYXJr
(1 row)
```

Decode
```shell
database_name=# select pgw_b64_decode('dGhpcyBpcyBkYXJr') as res;
     res      
--------------
 this is dark
(1 row)
```