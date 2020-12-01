#include "gestion_client.h"
#include "ui_gestion_client.h"
#include <QString>
#include <QMessageBox>
#include "crud_client.h"
#include <QThread>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
gestion_client::gestion_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_client)
{

    ui->setupUi(this);
    ui->tableView->setModel(tempclient.afficher());
    player= new QMediaPlayer(this);
    QPixmap pix("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/client icon.jpg");
    ui -> label_pixmap ->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));


}

gestion_client::~gestion_client()
{
    delete ui;
}

void gestion_client::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/Quitter.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    close();
}

void gestion_client::on_pushButton_ajoute_clicked()
{
    int i=ui->lineEdit_id->text().toInt();
    QString p=ui->lineEdit_prenom->text();
    QString n=ui->lineEdit_nom->text();
    int a=ui->lineEdit_age->text().toInt();
        crud_client c(i,p,n,a);
        bool test = c.ajouter();
        if (test)
        {
            player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/client ajouter.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);
            ui->tableView->setModel(tempclient.afficher());

            QMessageBox::information(nullptr,"AJOUT CLIENT","CLIENT AJOUTEE");
        }
        else
        {
            QMessageBox::warning(nullptr,"AJOUT CLIENT","CLIENT NON AJOUTEE");
        }


}
void gestion_client::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_supprimer->text().toInt();
    bool test = tempclient.supprimer(id);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/client supprimer.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);
        ui->tableView->setModel(tempclient.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER CLIENT","CLIENT SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER CLIENT","CLIENT NON SUPPRIMER !");
    }
}


void gestion_client::on_pushButton_modifer_clicked()
{
    int i=ui->lineEdit_id_modifer->text().toInt();
    QString p=ui->lineEdit_prenom_modifer->text();
    QString n=ui->lineEdit_nom_modifer->text();
    int a=ui->lineEdit_age_modifer->text().toInt();
        crud_client c(i,p,n,a);
        bool test = c.modifer();
        if (test)
        {
            player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/client modifier.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);
            ui->tableView->setModel(tempclient.afficher());

            QMessageBox::information(nullptr,"MODIFER CLIENT","CLIENT MODIFER");
        }
        else
        {
            QMessageBox::warning(nullptr,"MODIFER CLIENT","CLIENT NON MODIFER");
        }


}



void gestion_client::on_checkBox_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.trierid());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_client::on_checkBox_2_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.trierprenom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_client::on_checkBox_3_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.triernom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_client::on_checkBox_4_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.trierage());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}


void gestion_client::on_pushButton_impression_client_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/impression client.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);
    QPrinter printer;
    printer.setPrinterName("diserter printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableView->render(&printer);
}

void gestion_client::on_pushButton_rechercher_2_clicked()
{
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_id->text();
       ui->tableView_recherche_2->setModel(tempclient.afficher_nom(prenom));
}
//
void gestion_client::on_pushButton_rechercher_3_clicked()
{
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_id_supprimer->text();
       ui->tableView_recherche_3->setModel(tempclient.afficher_nom(prenom));
}

void gestion_client::on_pushButton_rechercher_4_clicked()
{
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_id_modifer->text();
       ui->tableView_recherche_4->setModel(tempclient.afficher_nom(prenom));
}


void gestion_client::on_pushButton_3_clicked()
{
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_prenom->text();
       ui->tableView_recherche_2->setModel(tempclient.afficher_prenom(prenom));
}

void gestion_client::on_radioButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/chercher client.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    ui->tableView->setModel(tempclient.afficher());
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(tempclient.afficher_nom(prenom));
}

void gestion_client::on_radioButton_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/chercher client.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    ui->tableView->setModel(tempclient.afficher());
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(tempclient.afficher_prenom(prenom));
}

void gestion_client::on_radioButton_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/chercher client.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    ui->tableView->setModel(tempclient.afficher());
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(tempclient.afficher_id(prenom));
}

void gestion_client::on_radioButton_4_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/chercher client.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    ui->tableView->setModel(tempclient.afficher());
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(tempclient.afficher_age(prenom));
}
