#include "gestion_administrateur.h"
#include "ui_gestion_administrateur.h"
#include "administrateur.h"
#include "agent.h"
#include <QFileDialog>
#include <QMessageBox>
#include<QPropertyAnimation>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>

gestion_administrateur::gestion_administrateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_administrateur)
{
    ui->setupUi(this);
    afficher();


    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

}

gestion_administrateur::~gestion_administrateur()
{
    delete ui;
}


void gestion_administrateur::afficher()
{


     proxy_Administrateur = new QSortFilterProxyModel();
    proxy_Administrateur->setSourceModel(Etmp.afficher());
        proxy_Administrateur->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxy_Administrateur->setFilterKeyColumn(selected_Administrateur);
    ui->tab_administrateur->setModel(proxy_Administrateur);

            proxy_Agent = new QSortFilterProxyModel();
            proxy_Agent ->setSourceModel(Atmp.afficher());
                proxy_Agent ->setFilterCaseSensitivity(Qt::CaseInsensitive);
                proxy_Agent ->setFilterKeyColumn(selected_Agent);
            ui->tab_agent->setModel(proxy_Agent );

}



void gestion_administrateur::on_pushButton_ajouter_2_clicked()
{
    int id =ui->lineEdit_id->text().toInt();
    QString nomadministrateur =ui->lineEdit_nom1->text();
    QString role=ui->lineEdit_role->text();

    Administrateur a(id,nomadministrateur,role);

    bool test=a.ajouter();
    // ui->stackedWidget->setCurrentIndex(1);
    if(test){
afficher();
QMessageBox::information(nullptr, QObject::tr("ajouter un administrateur"),
                    QObject::tr("administrateu ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}
    else{
        QMessageBox::critical(nullptr, QObject::tr("ajouter un commerçant"),
                    QObject::tr("commerçant non ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


 }

}



void gestion_administrateur::on_pushButton_editer_clicked()
{

    int id =ui->lineEdit_id_3->text().toInt();
    QString nomadministrateur =ui->lineEdit_nom2->text();
    QString role=ui->lineEdit_role2->text();

Administrateur a(id,nomadministrateur,role);


 bool test=a.editer();
 if(test){
     afficher();

QMessageBox::information(nullptr, QObject::tr("editer une administrateu"),
                 QObject::tr(" infraction edité.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}
 else{
     QMessageBox::critical(nullptr, QObject::tr("editer un administrateu"),
                 QObject::tr("infraction non edité.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void gestion_administrateur::on_pushButton_supprimer_clicked()
{

         int id =ui->lineEdit_idsupp->text().toInt();
         bool test=Etmp.supprimer(id);

         if(test){

afficher();
    QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("suppression effectuée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else{
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                         QObject::tr("suppression non effectuée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


      }


}

void gestion_administrateur::on_pushButton_ajouteragent_clicked()
{

    QString nom =ui->lineEdit_nom_2->text();
    QString statut=ui->lineEdit_statut->text();
     int tel =ui->lineEdit_number->text().toInt();
    QString adresse=ui->lineEdit_adresse->text();
    QString mail=ui->lineEdit_mail->text();

Agent a(nom,statut,tel,adresse,mail);
 bool test=a.ajouter();
    if(test){
afficher();
QMessageBox::information(nullptr, QObject::tr("ajouter un agent"),
                    QObject::tr("un agent ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}
    else{
        QMessageBox::critical(nullptr, QObject::tr("ajouter un  un agent"),
                    QObject::tr(" un agent non ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


 }

}


void gestion_administrateur::on_pushButton_editeragent_clicked()
{

    int tel =ui->lineEdit_number2->text().toInt();
    QString nom =ui->lineEdit_nom2_2->text();
    QString statut=ui->lineEdit_statut2->text();
    QString adresse=ui->lineEdit_adresse2->text();
    QString mail=ui->lineEdit_mail2->text();

Agent a(nom,statut,tel,adresse,mail);


 bool test=a.editer();
 if(test){
afficher();
QMessageBox::information(nullptr, QObject::tr("editer un agent"),
                 QObject::tr(" agent edité.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}
 else{
     QMessageBox::critical(nullptr, QObject::tr("editer un agent"),
                 QObject::tr("agent non edité.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


}
}


void gestion_administrateur::on_pushButton_suppagent_clicked()
{
    int tel =ui->lineEdit_nomsupp->text().toInt();;
    bool test=Atmp.supprimer(tel);

    if(test){

afficher();
QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("suppression non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


 }

}






void gestion_administrateur::on_comboBox_agent_currentIndexChanged(int index)
{
    selected_Agent=ui->comboBox_agent->currentIndex();
    afficher();

}

void gestion_administrateur::on_lineEdit_search_textChanged(const QString &arg1)
{
    proxy_Agent->setFilterFixedString(arg1);

}

void gestion_administrateur::on_comboBox_adm_currentIndexChanged(int index)
{
    selected_Administrateur=ui->comboBox_adm->currentIndex();
    afficher();
}

void gestion_administrateur::on_lineEdit_id3_textChanged(const QString &arg1)
{
     proxy_Administrateur->setFilterFixedString(arg1);
}


