#include "oracleqt.h"

oracleqt::oracleqt()
{

}
bool oracleqt::create_cnx(){

   bool test=false;
   QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("majdi257");
   db.setUserName("majdi");
   db.setPassword("bardi");

if(db.open())
    test=true;

return test;


}





