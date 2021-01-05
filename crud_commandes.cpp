#include "crud_commandes.h"

crud_commandes::crud_commandes()
{

}
crud_commandes::crud_commandes(int i,QString n,QString t)
{
    id_produit=i;
    nom_produit=n;
    type_produit=t;


}
bool crud_commandes::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO COMMANDE (id_produit,nom_produit,type_produit) VALUES  (:id_produit,:nom_produit,:type_produit)");
    QString res= QString::number(id_produit);
    query.bindValue(":id_produit",res);
    query.bindValue(":type_produit",type_produit);
    query.bindValue(":nom_produit",nom_produit);
    return query.exec();
}

bool crud_commandes::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM COMMANDE where id_produit=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}

bool crud_commandes::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDE SET id_produit=:id_produit,nom_produit=:nom_produit,type_produit=:type_produit,where id_produit=:id_produit");
    QString res= QString::number(id_produit);
    query.bindValue(":id_produit",id_produit);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":type_produit",type_produit);

    return query.exec();
}
QSqlQueryModel * crud_commandes::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from COMMANDE ");
    model->setHeaderData(0,Qt::Horizontal,"id_produit");
    model->setHeaderData(1,Qt::Horizontal,"nom_produit");
    model->setHeaderData(2,Qt::Horizontal,"type_produit");
    return model ;
}

QSqlQueryModel * crud_commandes::trierid_produit()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from COMMANDE ORDER BY id_produit");
    model->setHeaderData(0,Qt::Horizontal,"id_produit");
    model->setHeaderData(1,Qt::Horizontal,"nom_produit");
    model->setHeaderData(2,Qt::Horizontal,"type_produit");
    return model ;
}
QSqlQueryModel * crud_commandes::triernom_produit()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from COMMANDE ORDER BY nom_produit");
    model->setHeaderData(0,Qt::Horizontal,"id_produit");
    model->setHeaderData(1,Qt::Horizontal,"nom_produit");
    model->setHeaderData(2,Qt::Horizontal,"type_produit");
    return model ;
}
QSqlQueryModel * crud_commandes::triertype_produit()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from COMMANDE ORDER BY type_produit");
    model->setHeaderData(0,Qt::Horizontal,"id_produit");
    model->setHeaderData(1,Qt::Horizontal,"nom_produit");
    model->setHeaderData(2,Qt::Horizontal,"type_produit");
    return model ;
}
QSqlQueryModel * crud_commandes::afficher_commande(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from COMMANDE WHERE id_produit = '"+nom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id_produit");
    model->setHeaderData(1,Qt::Horizontal,"nom_produit");
    model->setHeaderData(2,Qt::Horizontal,"type_produit");
    return model ;
}


