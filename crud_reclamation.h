#ifndef CRUD_RECLAMATION_H
#define CRUD_RECLAMATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>



class crud_reclamation
{
    int id_reclamation;
    QString nom_reclamation;
    QString type_reclamation;

public:
    crud_reclamation();
    crud_reclamation(int,QString,QString);
    int get_id_reclamation(){return id_reclamation;}
    QString get_nom_reclamation(){return nom_reclamation;}
    QString get_type_reclamation(){return type_reclamation;}
    bool ajouter();
    bool supprimer(int);
    bool modifer();
    QSqlQueryModel *afficher();
    QSqlQueryModel  *trierid_reclamation();
    QSqlQueryModel  *triernom_reclamation();
    QSqlQueryModel  *triertype_reclamation();
    QSqlQueryModel *afficher_reclamation(QString);
};

#endif // CRUD_RECLAMATION_H
