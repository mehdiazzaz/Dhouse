#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Administrateur
{
public:
    Administrateur();
   Administrateur(int,QString,QString);

    QString get_nomadministrateur();
    QString get_role();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool chercher(QString);
    bool editer();


private:
   QString  nomadministrateur,role;
   int id;
};





#endif // ADMINISTRATEUR_H
