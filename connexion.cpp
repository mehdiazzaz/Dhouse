#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("Mootaz");//inserer nom de l'utilisateur
db.setPassword("taztaz");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connexion::fermerconnexion()
{
    db.close();
}
