#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Agent
{
public:
    Agent();

   Agent(QString,QString,int,QString,QString);

    QString get_nom();
    QString get_adresse();
    QString get_mail();
    QString get_statut();
    int get_tel();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool chercher(QString);
    bool editer();


private:
   QString  nom,adresse,mail,statut;
   int tel;
};

#endif // AGENT_H
