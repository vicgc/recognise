#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

// conn interface - conn, close, insert -> 
// tables + update
// Open the db connection
// prepare the statements
// adjust prepared statements params
// execute the statements
// loop through resultset
// close resultset
// close prepared statement
// close db connection

int main() {
   const char * sql;
   const char * class_recogn;
   const char * sec_recogn;
   
   try {
      connection C("dbname=recognise user=synod password= \
      hostaddr=127.0.0.1 port=5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      /* Create SQL statement */
      sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

      class_recogn = "CREATE TABLE class_recogn(" \
          "id_no serial NOT NULL," \
          "first_name varchar(20) NOT NULL," \
          "last_name varchar(20) NOT NULL," \
          "classes_missed integer NOT NULL," \
          "dates_missed varchar(200) NOT NULL," \
          "last_time_stamp TIMESTAMP," \

          "PRIMARY KEY(id_no));";

      sec_recogn = "CREATE TABLE sec_recogn (" \
          "id_no serial NOT NULL," \
          "first_name varchar(20) NOT NULL," \
          "last_name varchar(20) NOT NULL," \
          "last_time_stamp TIMESTAMP, " \
          "zone varchar(20) NOT NULL, "\

          "PRIMARY KEY (id_no));" ;

      /* Create a transactional object. */
      work W(C);
      
      /* Execute SQL query */
      W.exec( sec_recogn );
      W.commit();
      cout << "Table created successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e){
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}
