#include "gestion_commande.h"
#include "ui_gestion_commande.h"
#include "crud_commandes.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
gestion_commande::gestion_commande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_commande)
{
    ui->setupUi(this);
}

gestion_commande::~gestion_commande()
{
    delete ui;
}

void gestion_commande::on_pushButton_clicked()
{
    int i=ui->lineEdit_id_produit->text().toInt();
     QString n=ui->lineEdit_nom_produit->text();
    QString t=ui->lineEdit_3->text();

        crud_commandes c(i,n,t);
        bool test = c.ajouter();
        if (test)
        {

            QMessageBox::information(nullptr,"AJOUT CLIENT","COMMANDE AJOUTEE");
        }
        else
        {
            QMessageBox::warning(nullptr,"AJOUT CLIENT","COMMANDE NON AJOUTEE");
        }
}

void gestion_commande::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_supprimer->text().toInt();
    bool test = tempcommandes.supprimer(id);
    if (test)
    {

        ui->tableView->setModel(tempcommandes.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER COMMANDE","COMMANDE SUPPRIMEE !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER COMMANDE","COMMANDE NON SUPPRIMEE !");
    }
}

void gestion_commande::on_pushButton_modifier_clicked()
{
    int i=ui->lineEdit_id_produit_modifier->text().toInt();
    QString t=ui->lineEdit_nom_produit_modifier->text();
  QString n=ui->lineEdit_type_produit_modifier->text();
bool test = ui->lineEdit_id_produit_modifier==NULL and ui->lineEdit_nom_produit_modifier==NULL and ui->lineEdit_type_produit_modifier==NULL ;
if (test)
{
    QMessageBox::information(nullptr,"ATTENTION","veuillez remplir toutes les cases");

  }
else
{
    bool test2 = tempcommandes.supprimer(i);
crud_commandes c(i,n,t);
test2=c.ajouter();
if (test2)
{

    ui->tableView->setModel(tempcommandes.afficher());

    QMessageBox::information(nullptr,"MODIFICATION REUSSIE","LA COMMANDE A ETE BIEN MODIFIEE");
ui->tableView->setModel(tempcommandes.afficher());

}
else
{
    QMessageBox::critical(nullptr,"ATTENTION","probléme de modification");

}
}

}

void gestion_commande::on_checkBox_clicked()
{
        bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempcommandes.afficher());

              ui->tableView->setModel(tempcommandes.trierid_produit());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier commande"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void gestion_commande::on_checkBox_2_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempcommandes.afficher());

              ui->tableView->setModel(tempcommandes.triernom_produit());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier commande"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void gestion_commande::on_checkBox_3_clicked()

   {

        bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempcommandes.afficher());

              ui->tableView->setModel(tempcommandes.triertype_produit());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier commande"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }


}
void gestion_commande::on_pushButton_5_clicked()
{

    QPrinter printer;
        printer.setPrinterName("diserter printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tableView->render(&printer);

}


void gestion_commande::on_pushButton_4_clicked()
{

    ui->tableView->setModel(tempcommandes.afficher());
        QString nom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(tempcommandes.afficher_commande(nom));
}
