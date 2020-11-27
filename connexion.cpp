#include "connexion.h"

connecter::connecter()
{

}
bool connecter::creatconnect()
{
    bool test=false;
       QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("projet2a");
       db.setUserName("mehdi");
       db.setPassword("azert");
       if (db.open())
           test=true;

       return test;
}
//
