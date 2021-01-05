#ifndef PUBLICITE_H
#define PUBLICITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Publicite
{
private:
    int idPub;
    QString nom,date_ajout;
public:
    Publicite();
    Publicite(int,QString,QString);
    int getIdPub();
    QString getNom();
    QString getDateAjout();

    //Les fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * combo_box();

    //Les fonctions Avancées
    QSqlQueryModel * trierIdPub();

};

#endif // PUBLICITE_H
