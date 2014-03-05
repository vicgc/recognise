#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

// clang++ update.cpp -o update -lpqxx -lpq

int main() {
   const char * sql;
   const char * class_recogn;
   
   try {
      connection C("dbname=recognise user=synod password= \
      hostaddr=127.0.0.1 port=5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      
      /* Create a transactional object. */
      work W(C);
      /* Create  SQL UPDATE statement */
      sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1";

      class_recogn = "UPDATE class_recogn SET classes_missed=4 where id_no=1";

      /* Execute SQL query */
      W.exec( class_recogn );
      W.commit();
      cout << "Records updated successfully" << endl;
      
      /* Create SQL SELECT statement */
      sql = "SELECT * from class_recogn";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
         cout << "id_no = " << c[0].as<int>() << endl;
         cout << "fname = " << c[1].as<string>() << endl;
         cout << "lname = " << c[2].as<string>() << endl;
         cout << "classes_missed = " << c[3].as<int>() << endl;
         cout << "dates_missed = " << c[4].as<string>() << endl;
         cout << "last_time = " << c[5].as<string>() << endl;
      }
      cout << "Operation done successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}
