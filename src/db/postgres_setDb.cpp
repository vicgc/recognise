#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
  
// clang++ -o pq postgres.cpp -lpqxx -lpq

int main() {
	PGconn          *conn;
	PGresult        *res;
	int             rec_count;
	int             row;
	int             col;

	conn = PQconnectdb("dbname=benchcare host=localhost user=synod password=");

	if (PQstatus(conn) == CONNECTION_BAD) {
	     puts("We were unable to connect to the database");
	     exit(0);
	}

	res = PQexec(conn,
	     "update people set phonenumber=\'5055559999\' where id=3");

	res = PQexec(conn,
	     "select lastname,firstname,phonenumber from people order by id");

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
	     puts("We did not get any data!");
	     exit(0);
	}

	rec_count = PQntuples(res);

	printf("We received %d records.\n", rec_count);
	puts("==========================");

	for (row=0; row<rec_count; row++) {
	     for (col=0; col<3; col++) {
	             printf("%s\t", PQgetvalue(res, row, col));
	     }
	     puts("");
	}

	puts("==========================");

	PQclear(res);
	PQfinish(conn);
	return 0;
}
