#include "crud_produit.h"

crud_produit::crud_produit()
{

}
crud_produit::crud_produit(int i,QString n,QString t,int p,QString pr)
{
    id=i;
    nom=n;
    type=t;
    prix=p;
    promotion=pr;
}
bool crud_produit::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PORDUITC (id,nom,type,prix,promotion) VALUES (:id,:nom,:type,:prix,:promotion)");
    QString res= QString::number(id);
    query.bindValue(":id",id);
     query.bindValue(":nom",nom);
    query.bindValue(":type",type);
   query.bindValue(":prix",prix);
    query.bindValue(":promotion",promotion);
    return query.exec();
}
bool crud_produit::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PORDUITC where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}

bool crud_produit ::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE  PORDUITC SET id=:id,nom=:nom,type=:type,prix=:prix,promotion=:promotion where id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    query.bindValue(":promotion",promotion);
    return query.exec();
}



QSqlQueryModel * crud_produit ::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from PORDUITC ");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"description");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"prix_apres_promotion");
    model->setHeaderData(4,Qt::Horizontal,"promotion");
    return model ;
}
QSqlQueryModel * crud_produit::trierid()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from PORDUITC ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"description");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"prix_apres_promotion");
    model->setHeaderData(4,Qt::Horizontal,"promotion");
    return model ;
}
QSqlQueryModel * crud_produit::trierpromotion()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from PORDUITC ORDER BY prix");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"description");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"prix_apres_promotion");
    model->setHeaderData(4,Qt::Horizontal,"promotion");
    return model ;
}
QSqlQueryModel * crud_produit::trierprix()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from PORDUITC ORDER BY promotion");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"description");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"prix_apres_promotion");
    model->setHeaderData(4,Qt::Horizontal,"promotion");
    return model ;
}
QSqlQueryModel * crud_produit::afficher_nom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from PORDUITC WHERE id = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"description");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"prix_apres_promotion");
    model->setHeaderData(4,Qt::Horizontal,"promotion");
    return model ;
}
//
