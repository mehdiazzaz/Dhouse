#include "crud_client.h"

crud_client::crud_client()
{

}
crud_client::crud_client(int i,QString p,QString n,int a)
{
    id=i;
    prenom=p;
    nom=n;
    age=a;
}
bool crud_client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTC (id,prenom,nom,age) VALUES (:id,:prenom,:nom,:age)");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);
    return query.exec();
}
bool crud_client::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTC where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}

bool crud_client ::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE  CLIENTC SET id=:id,prenom=:prenom,nom=:nom,age=:age where id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);
    return query.exec();
}



QSqlQueryModel * crud_client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTC ");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::trierid()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTC ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::trierprenom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTC ORDER BY prenom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::triernom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTC ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::trierage()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTC ORDER BY age");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::afficher_nom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTC WHERE id = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::afficher_prenom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTC WHERE prenom = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::afficher_id(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTC WHERE nom = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_client::afficher_age(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTC WHERE age = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}

//
