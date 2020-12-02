#ifndef CRUD_COMMANDES_H
#define CRUD_COMMANDES_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class crud_commandes
{
    int id_produit;
    QString nom_produit;
    QString type_produit;


public:
    crud_commandes();
    crud_commandes(int,QString,QString);
    int get_id_produit(){return id_produit;}
    QString get_nom_produit(){return nom_produit;}
    QString get_type_produit(){return type_produit;}
    bool ajouter();
    bool supprimer(int);
    bool modifer();
    QSqlQueryModel *afficher();
    QSqlQueryModel  *trierid_produit();
    QSqlQueryModel  *triernom_produit();
    QSqlQueryModel  *triertype_produit();
    QSqlQueryModel *afficher_commande(QString);
};

#endif // CRUD_COMMANDES_H
