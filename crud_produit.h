#ifndef CRUD_PRODUIT_H
#define CRUD_PRODUIT_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class crud_produit
{
    int id;
    QString nom;
    QString type ;
    int prix;
    QString promotion ;
public:
    crud_produit();
    crud_produit(int,QString,QString,int,QString);
    int get_id(){return id;}
    QString get_nom(){return nom;}
     QString get_type(){return type;}
    int get_prix(){return prix;}
     QString get_promotion(){return promotion;}
    bool ajouter();
    bool supprimer(int);
    bool modifer();
    QSqlQueryModel *afficher();
    QSqlQueryModel *trierid();
    QSqlQueryModel *trierpromotion();
    QSqlQueryModel *trierprix();
    QSqlQueryModel *afficher_nom(QString);

//
};

#endif // CRUD_PRODUIT_H
