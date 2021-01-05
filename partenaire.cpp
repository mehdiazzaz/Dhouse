#include "partenaire.h"

Partenaire::Partenaire()
{
    CIN=0;
    nom="";
    prenom="";

}
Partenaire::Partenaire(int CIN,QString nom,QString prenom)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
}
QString Partenaire::getNom(){return  nom;}
QString Partenaire::getPrenom(){return prenom;}
int Partenaire::getCIN(){return  CIN;}

bool Partenaire::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(CIN,'f',8);
    query.prepare("INSERT INTO Partenaire (CIN, nom, prenom) "
                           "VALUES (:CIN, :nom, :prenom)");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    return query.exec();
}
QSqlQueryModel * Partenaire::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from partenaire");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));


    return model;
}
bool Partenaire::supprimer(int CIN)
{
    QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("Delete from partenaire where CIN = :CIN");
    query.bindValue(":CIN", res);


    return query.exec();
}
bool Partenaire::modifier()
{
    QSqlQuery query;
    QString CIN= QString::number(this->CIN);
    QString nom= this->nom;
    QString prenom= this->prenom;
    query.prepare("UPDATE Partenaire SET nom =:nom , prenom=:prenom  WHERE CIN =:CIN");
    query.bindValue(":CIN",CIN);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

        return  query.exec();
}
QSqlQueryModel * Partenaire::combo_box()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("Select CIN from partenaire");

    return model;
}

QSqlQueryModel * Partenaire::trier_CIN()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from Partenaire\
                             Order by CIN DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

        return model;
}
QSqlQueryModel * Partenaire::impression_CIN()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From partenaire WHERE nom ='" +nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

    return model;
}
