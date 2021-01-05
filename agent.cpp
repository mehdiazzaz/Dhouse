#include "agent.h"

Agent::Agent()
{
nom="";
adresse="";
mail="";
statut="";
}

Agent::Agent(QString nom,QString statut,int tel,QString adresse,QString mail){

    this->tel=tel;
    this->nom=nom;
    this->statut=statut;
    this->adresse=adresse;
    this->mail=mail;

}

QString Agent:: get_nom(){return nom;}
QString Agent:: get_statut(){return statut;}
QString Agent:: get_adresse(){return adresse;}
QString Agent:: get_mail(){return mail;}

int Agent:: get_tel(){return tel;}

bool Agent::ajouter(){
    QSqlQuery query;
    QString res= QString::number(tel);
    query.prepare("INSERT INTO agent(nom,statut,tel,adresse,mail)"
                    "VALUES (:nom, :statut, :tel, :adresse, :mail)");

    query.bindValue(":nom",nom);
    query.bindValue(":statut",statut);
    query.bindValue(":tel",res);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mail",mail);

    return query.exec();

}
QSqlQueryModel * Agent::afficher(){

    QSqlQueryModel * model=new QSqlQueryModel();



    model->setQuery("select * from agent");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom salariés"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("N°tel"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));

    return model;

}
bool Agent::supprimer(QString nom){
    QSqlQuery query;

    query.prepare("DELETE FROM agent WHERE nom=:nom");
     query.bindValue(":nom",nom);

     return query.exec();
}

bool Agent::editer(){
    QSqlQuery query;
    QString r= QString::number(tel);
    query.prepare("UPDATE agent SET nom=:nom,statut=:statut,tel=:tel,adresse=:adresse,mail=:mail WHERE tel=:tel");
   query.bindValue(":nom",nom);
   query.bindValue(":statut",statut);
   query.bindValue(":tel",tel);
   query.bindValue(":adresse",adresse);
   query.bindValue(":mail",mail);



    return query.exec();
}
