#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main() {
   const char * class_recogn;
   const char * sql;
   
   try {
      connection C("dbname=recognise user=synod password= \
      hostaddr=127.0.0.1 port=5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }

      class_recogn = "INSERT INTO class_recogn" \
      "(first_name,last_name,classes_missed,dates_missed,last_time_stamp)" \
      "VALUES ('Ian', 'Juma', 1, 12, 'Wed Mar  5 10:04:42 2014');";

      // import datetime.datetime
      // date = datetime.utcnow()
      // datetime.ctime(date)


      /* Create SQL statement */
      sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
      "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
      "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
      "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
      "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

      /* Create a transactional object. */
      work W(C);
      
      /* Execute SQL query */
      W.exec( class_recogn );
      W.commit();
      cout << "Records created successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}
