#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>


class Partenaire
{
private:
    QString nom,prenom;
        int CIN;
public:
    Partenaire();
    Partenaire(int ,QString,QString);
    int getCIN();
    QString getNom();
    QString getPrenom();

    //Les fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * combo_box();

    //Les fonctions avancées
    QSqlQueryModel * trier_CIN();
    QSqlQueryModel * impression_CIN();



};

#endif // PARTENAIRE_H
