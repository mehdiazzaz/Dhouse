#include "crud_reclamation.h"


crud_reclamation::crud_reclamation()
{

}
crud_reclamation::crud_reclamation(int d,QString o,QString y)
{
    id_reclamation=d;
    nom_reclamation=o;
    type_reclamation=y;

}
bool crud_reclamation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RECLAMATION (id_reclamation,nom_reclamation,type_reclamation) VALUES  (:id_reclamation,:nom_reclamation,:type_reclamation)");
    QString res= QString::number(id_reclamation);
    query.bindValue(":id_reclamation",res);
    query.bindValue(":type_reclamation",type_reclamation);
    query.bindValue(":nom_reclamation",nom_reclamation);
    return query.exec();
}
bool crud_reclamation::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RECLAMATION where id_reclamation=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
bool crud_reclamation::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE RECLAMATION SET id_reclamation=:id_reclamation,nom_reclamation=:nom_reclamation,type_reclamation=:type_reclamation,where id_reclamation=:id_reclamation");
    QString res= QString::number(id_reclamation);
    query.bindValue(":id_reclamation",id_reclamation);
    query.bindValue(":nom_reclamation",nom_reclamation);
    query.bindValue(":type_reclamation",type_reclamation);

    return query.exec();
}
QSqlQueryModel * crud_reclamation::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION ");
    model->setHeaderData(0,Qt::Horizontal,"id_reclamation");
    model->setHeaderData(1,Qt::Horizontal,"nom_reclamation");
    model->setHeaderData(2,Qt::Horizontal,"type_reclamation");
    return model ;
}

QSqlQueryModel * crud_reclamation::trierid_reclamation()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from RECLAMATION ORDER BY id_reclamation");
    model->setHeaderData(0,Qt::Horizontal,"id_reclamation");
    model->setHeaderData(1,Qt::Horizontal,"nom_reclamation");
    model->setHeaderData(2,Qt::Horizontal,"type_reclamation");
    return model ;
}
QSqlQueryModel * crud_reclamation::triernom_reclamation()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from RECLAMATION ORDER BY nom_reclamation");
    model->setHeaderData(0,Qt::Horizontal,"id_reclamation");
    model->setHeaderData(1,Qt::Horizontal,"nom_reclamation");
    model->setHeaderData(2,Qt::Horizontal,"type_reclamation");
    return model ;
}
QSqlQueryModel * crud_reclamation::triertype_reclamation()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from RECLAMATION ORDER BY type_reclamation");
    model->setHeaderData(0,Qt::Horizontal,"id_reclamation");
    model->setHeaderData(1,Qt::Horizontal,"nom_reclamation");
    model->setHeaderData(2,Qt::Horizontal,"type_reclamation");
    return model ;
}
QSqlQueryModel * crud_reclamation::afficher_reclamation(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION WHERE id_reclamation = '"+nom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id_reclamation");
    model->setHeaderData(1,Qt::Horizontal,"nom_reclamation");
    model->setHeaderData(2,Qt::Horizontal,"type_reclamation");
    return model ;
}

