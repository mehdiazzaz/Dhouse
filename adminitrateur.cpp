#include "adminitrateur.h"
//modifier

Administrateur::Administrateur()
{
    id=0;
    nomadministrateur="";
    role="";
}



Administrateur::Administrateur(int id,QString nomadministrateur,QString role){

    this->id=id;
    this->nomadministrateur=nomadministrateur;
    this->role=role;

}

QString Administrateur:: get_nomadministrateur(){return nomadministrateur;}
QString Administrateur:: get_role(){return role;}

int Administrateur:: get_id(){return id;}

bool Administrateur::ajouter(){
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO administrateur( id, nomadministrateur,role)"
                    "VALUES (:id, :nomadministrateur, :role)");
   query.bindValue(":id",res);
    query.bindValue(":nomadministrateur",nomadministrateur);
    query.bindValue(":role",role);

    return query.exec();

}
QSqlQueryModel * Administrateur::afficher(){

    QSqlQueryModel * model=new QSqlQueryModel();



    model->setQuery("select * from administrateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom administrateur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("role"));

    return model;

}
bool Administrateur::supprimer(int id){
    QSqlQuery query;
   QString res= QString::number(id);
    query.prepare("DELETE FROM administrateur WHERE id=:id");
     query.bindValue(":id",res);

     return query.exec();
}

bool Administrateur::editer(){
    QSqlQuery query;
    QString r= QString::number(id);
    query.prepare("UPDATE administrateur SET id=:id,nomadministrateur=:nomadministrateur,role=:role WHERE id=:id");
   query.bindValue(":id",r);
   query.bindValue(":nomadministrateur",nomadministrateur);
   query.bindValue(":role",role);


    return query.exec();
}
