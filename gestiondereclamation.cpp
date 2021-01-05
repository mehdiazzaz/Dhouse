#include "gestiondereclamation.h"
#include "ui_gestiondereclamation.h"
#include "crud_reclamation.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
#include"dialog.h"

gestiondereclamation::gestiondereclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondereclamation)
{
    ui->setupUi(this);
    ui->tableView_rec->setModel(tempreclamation.afficher());
}

gestiondereclamation::~gestiondereclamation()
{
    delete ui;
}


void gestiondereclamation::on_pushButton_clicked()
{
    int d=ui->lineEdit_id_reclamation_2->text().toInt();
     QString o=ui->lineEdit_nom_reclamation->text();
    QString y=ui->lineEdit_type_reclamation_2->text();

        crud_reclamation c(d,o,y);
        bool test = c.ajouter();
        if (test)
        {


            QMessageBox::information(nullptr,"AJOUT RECLAMATION","RECLAMATION AJOUTEE");
        }
        else
        {
            QMessageBox::warning(nullptr,"AJOUT RECLAMATION","RECLAMATION NON AJOUTEE");
        }
}

void gestiondereclamation::on_pushButton_2_clicked()
{
    int id_reclamation = ui->lineEdit_id_reclamationsupp->text().toInt();
    bool test = tempreclamation.supprimer(id_reclamation);
    if (test)
    {

        ui->tableView_rec->setModel(tempreclamation.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER CLIENT","COMMANDE SUPPRIMEE !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER CLIENT","COMMANDE NON SUPPRIMEE !");
    }
}

void gestiondereclamation::on_pushButton_3_clicked()
{

    int d=ui->lineEdit_id_reclamation_modif->text().toInt();
    QString o=ui->lineEdit_nom_reclamation_modif->text();
    QString y=ui->lineEdit_type_reclamation_modif->text();

    bool test = ui->lineEdit_id_reclamation_modif==NULL and ui->lineEdit_nom_reclamation_modif==NULL and ui->lineEdit_type_reclamation_modif==NULL ;
    if (test)
    {
        QMessageBox::information(nullptr,"ATTENTION","veuillez remplir toutes les cases");

      }
    else
    {
        bool test2 = tempreclamation.supprimer(d);
    crud_reclamation c(d,o,y);
    test2=c.ajouter();
    if (test2)
    {
        QMessageBox::information(nullptr,"MODIFICATION REUSSIE","LA COMMANDE A ETE BIEN MODIFIEE");
    ui->tableView_rec->setModel(tempreclamation.afficher());

    }
    else
    {
        QMessageBox::critical(nullptr,"ATTENTION","probléme de modification");

    }
}
}

void gestiondereclamation::on_trierid_reclamation_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView_rec->setModel(tempreclamation.afficher());

              ui->tableView_rec->setModel(tempreclamation.trierid_reclamation());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier reclamation"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void gestiondereclamation::on_triernom_reclamation_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView_rec->setModel(tempreclamation.afficher());

              ui->tableView_rec->setModel(tempreclamation.triernom_reclamation());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier reclamation"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void gestiondereclamation::on_triertype_reclamation_clicked()
{

    bool test = true;
      if (test)
          {
          ui->tableView_rec->setModel(tempreclamation.afficher());

              ui->tableView_rec->setModel(tempreclamation.triertype_reclamation());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier commande"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void gestiondereclamation::on_pushButton_6_clicked()
{
    QPrinter printer;
        printer.setPrinterName("diserter printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tableView_rec->render(&printer);
}

void gestiondereclamation::on_pushButton_4_clicked()
{
    Dialog d;
    d.exec();
}


void gestiondereclamation::on_pushButton_5_clicked()
{
    ui->tableView_rec->setModel(tempreclamation.afficher());
        QString nom = ui->lineEdit_recherche1->text();
       ui->tableView_recherche1->setModel(tempreclamation.afficher_reclamation(nom));
}
