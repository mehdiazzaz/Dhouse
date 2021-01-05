#include "publicite.h"

Publicite::Publicite()
{
    idPub=0;
    nom="";
    date_ajout="";
}

Publicite::Publicite(int idPub ,QString nom,QString date_ajout)
{
    this->idPub=idPub;
    this->nom=nom;
    this->date_ajout=date_ajout;
}

QString Publicite::getNom(){return  nom;}
QString Publicite::getDateAjout(){return date_ajout;}
int Publicite::getIdPub(){return  idPub;}

QSqlQueryModel * Publicite::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("Select * from publicté");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idPub"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));

     return model;
}

bool Publicite::supprimer(int idPub)
{
    QSqlQuery query;
    QString res= QString::number(idPub);
    query.prepare("Delete from publicité where idF = :idF");
    query.bindValue(":idF", res);
    return query.exec();
}

bool Publicite::modifier()
{
    QSqlQuery query;
    QString idPub_modif= QString::number(this->idPub);
    QString nom_modif= this->nom;
    QString date_ajout_modif= this->date_ajout;
    query.prepare("UPDATE Publicité SET nom =:nom , date_ajout=:date_ajout  WHERE idF =:idF");
    query.bindValue(":idF",idPub_modif);
    query.bindValue(":nom",nom_modif);
    query.bindValue(":date_ajout",date_ajout_modif);
    return  query.exec();
}

QSqlQueryModel * Publicite::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select idF from publicité");
    return model;
}

QSqlQueryModel * Publicite::trierIdPub()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from publicité\
                         Order by idF ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));

    return model;
}
