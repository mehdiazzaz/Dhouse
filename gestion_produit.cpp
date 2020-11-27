#include "gestion_produit.h"
#include "ui_gestion_produit.h"
#include <QString>
#include <QMessageBox>
#include "crud_produit.h"
#include <QThread>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
gestion_produit::gestion_produit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_produit)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempproduit.afficher());
    player= new QMediaPlayer(this);
    QPixmap pix("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/icon promotion.jpg");
    ui -> label_pic_promo ->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));


}

gestion_produit::~gestion_produit()
{
    delete ui;
}

void gestion_produit::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/Quitter.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    close();
}

void gestion_produit::on_pushButton_4_clicked()
{
    int i=ui->lineEdit_id_porduit->text().toInt();
    QString n=ui->lineEdit_nom_porduit->text();
    QString t=ui->lineEdit_type_porduit->text();
    int p=ui->lineEdit_prix_produit->text().toInt();;
    QString pr=ui->lineEdit_promortion_porduit->text();
        crud_produit s(i,n,t,p,pr);
        bool test = s.ajouter();
        if (test)
        {
            player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/promotion ajouter.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);
            ui->tableView->setModel(tempproduit.afficher());

            QMessageBox::information(nullptr,"AJOUT pormotion","promotion AJOUTEE");
        }
        else
        {
            QMessageBox::warning(nullptr,"AJOUT promotion","poromtion NON AJOUTEE");
        }


}



void gestion_produit::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_id_supprimer->text().toInt();
    bool test = tempproduit.supprimer(id);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/promotion supprimer.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);
        ui->tableView->setModel(tempproduit.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER pormotion","pormotion SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER promotion","promotion NON SUPPRIMER !");
    }
}
void gestion_produit::on_pushButton_2_clicked()
{

    int i=ui->lineEdit_id_porduit_modifer->text().toInt();
    QString n=ui->lineEdit_nom_porduit_modifer->text();
    QString t=ui->lineEdit_type_porduit_modifer->text();
    int p=ui->lineEdit_prix_produit_modifer->text().toInt();
    QString pr=ui->lineEdit_promortion_porduit_modifer->text();
           crud_produit s(i,n,t,p,pr);
            bool test = s.modifer();
            if (test)
            {
                player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/promotion modifier.mp3"));
                            player->play();
                            qDebug()<<player->errorString();
                            QThread::sleep(1);
                ui->tableView->setModel(tempproduit.afficher());

                QMessageBox::information(nullptr,"MODIFER promotion","pormotion MODIFER");
            }
            else
            {
                QMessageBox::warning(nullptr,"MODIFER promotion","pormotion NON MODIFER");

            }
               }


void gestion_produit::on_checkBox_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempproduit.afficher());

              ui->tableView->setModel(tempproduit.trierid());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void gestion_produit::on_checkBox_2_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempproduit.afficher());

                  ui->tableView->setModel(tempproduit.trierprix());


              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void gestion_produit::on_checkBox_3_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableView->setModel(tempproduit.afficher());

                  ui->tableView->setModel(tempproduit.trierpromotion());


              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void gestion_produit::on_pushButton_5_clicked()
{
    ui->tableView->setModel(tempproduit.afficher());
        QString prenom = ui->lineEdit_id_porduit->text();
       ui->tableView_2->setModel(tempproduit.afficher_nom(prenom));
}

void gestion_produit::on_pushButton_7_clicked()
{
    ui->tableView->setModel(tempproduit.afficher());
        QString prenom = ui->lineEdit_id_supprimer->text();
       ui->tableView_3->setModel(tempproduit.afficher_nom(prenom));
}

void gestion_produit::on_pushButton_8_clicked()
{
    ui->tableView->setModel(tempproduit.afficher());
        QString prenom = ui->lineEdit_id_porduit_modifer->text();
       ui->tableView_4->setModel(tempproduit.afficher_nom(prenom));
}
//
void gestion_produit::on_pushButton_6_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/impression promotion.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);
    QPrinter printer;
    printer.setPrinterName("diserter printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableView->render(&printer);
}
