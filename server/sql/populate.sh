#!/bin/bash

if [ $# -ne 1 ]
then
	echo "USAGE $0 <db_file>"
	exit 1
fi

SQL_PATH=.
DB_PATH="$1"

for sql in "${SQL_PATH}/"{clients.sql,banks.sql,branches.sql,accounts.sql}
do
	cat "${sql}" | sqlite3 "${DB_PATH}"
done
