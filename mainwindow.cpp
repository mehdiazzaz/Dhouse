#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtPrintSupport>
#include <QPrintDialog>
#include <QMessageBox>
#include <QDebug>
#include <QWidget>
#include <QTableView>
#include <QLCDNumber>

#include "partenaire.h"
#include "publicite.h"
#include "statisque.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabPart_2->setModel(tmppartenaire.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouterPart_2_clicked()
{
    QString nom= ui->lineEdit_nom_3->text();
    QString prenom= ui->lineEdit_prenom_3->text();
    int CIN = ui->lineEdit_cin_2->text().toLong();

    Partenaire p(CIN,nom,prenom);
    if(CIN < 999999 && CIN > 0)
    {
        bool test=p.ajouter();
        if(test)
        {
            ui->comboCINsupp_2->setModel(tmppartenaire.combo_box());
                  ui->comboCINmodif_2->setModel(tmppartenaire.combo_box());
                  ui->tabPart_2->setModel(tmppartenaire.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter un partenaire"),
                              QObject::tr("Partenaire ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else

            QMessageBox::critical(nullptr, QObject::tr("Ajouter un Partenaire"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                   QObject::tr("6 premier chiffres = CIN!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pb_supprimerPart_2_clicked()
{
    int CIN = ui->comboCINsupp_2->currentText().toInt();
    bool test=tmppartenaire.supprimer(CIN);
    if(test)
    {
        ui->tabPart_2->setModel(tmppartenaire.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un partenaire"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un partenaire"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifierPart_2_clicked()
{
    int CIN = ui->comboCINmodif_2->currentText().toInt();
    QString nom= ui->lineEdit_nom_4->text();
    QString prenom= ui->lineEdit_prenom_4->text();
    Partenaire p(CIN,nom,prenom);
    bool test=p.modifier();
    if(test)
    {
        ui->tabPart_2->setModel(tmppartenaire.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un partenaire"),
                          QObject::tr("Partenaire modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un partenaire"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}
//impression profil
/*void MainWindow::on_ch_nom_2_clicked()
{

}*/

void MainWindow::on_trier_cin_2_clicked()
{
    ui->tabPart_2->setModel(tmppartenaire.trier_CIN());
}

void MainWindow::on_pb_ajouterPub_2_clicked()
{
    int idPub = ui->lineEdit_idPub_2->text().toInt();
    QString nom= ui->lineEdit_nomPub_2->text();
    QString date_ajout= ui->lineEdit_date_3->text();
    Publicite p(idPub,nom, date_ajout);
    bool test=p.afficher();
    if(test)
    {
        ui->comboPubsupp_2->setModel(tmppublicite.combo_box());
        ui->comboFmodif_2->setModel(tmppublicite.combo_box());
        ui->tabPublicite_2->setModel(tmppublicite.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une publicité"),
                          QObject::tr("Publicité Ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une publicité"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_trier_id_2_clicked()
{
    ui->tabPublicite_2->setModel(tmppublicite.trierIdPub());
}

/*void MainWindow::on_pushButton_Statistique_clicked()
{

}*/

void MainWindow::on_pb_supprimerPub_2_clicked()
{
    int idPub = ui->comboPubsupp_2->currentText().toInt();
    bool test=tmppublicite.supprimer(idPub);
    if(test)
    {
        ui->tabPublicite_2->setModel(tmppublicite.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer une publicité"),
                            QObject::tr("Publicité supprimée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une publicitée"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifierPub_2_clicked()
{
    int idPub = ui->comboFmodif_2->currentText().toInt();
    QString nom= ui->lineEdit_nomPub_3->text();
    QString date_ajout= ui->lineEdit_date_4->text();
    Publicite p(idPub,nom, date_ajout);
    bool test=p.modifier();
    if(test)
    {
        ui->tabPublicite_2->setModel(tmppublicite.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier une publicité"),
                          QObject::tr("Publicité modifiée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une publicité"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_combo_trie_rech_2_currentIndexChanged(const QString &arg1)
{
    if(arg1=="")
                    ui->tabPart_2->setModel(tmppartenaire.afficher());
                if(arg1 == "Trie par CIN")
                    ui->tabPart_2->setModel(tmppartenaire.trier_CIN());
}

void MainWindow::on_ch_nom_2_clicked()
{
    int id=ui->lineEdit_cin_2->text().toInt();
    QString CIN="";
    QString nom="";
    QString prenom="";
    QString res=QString::number(id);
    QSqlQuery query;
    query.prepare("Select * From partenaire where CIN_partenaire = :id");
    query.bindValue(":id",res);
    if(query.exec())
    {
        while(query.next())
        {
            CIN=query.value(0).toString();
            nom=query.value(1).toString();
            prenom=query.value(2).toString();
        }
    }
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog *dialog=new QPrintDialog(&printer);
    if(dialog->exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);
                        painter.begin(&printer);
                        int iYPos = 0;
                        int iWidth = printer.width();
                        int iHeight = printer.height();
                        QPixmap pxPic;
                        pxPic.load("C:/pics", "PNG");
                        QSize s(iWidth/3, iHeight/5);
                        QPixmap pxScaledPic = pxPic.scaled(s, Qt::KeepAspectRatio, Qt::FastTransformation);
                        painter.drawPixmap(3500, iYPos, pxScaledPic.width(), pxScaledPic.height(), pxScaledPic);
                        iYPos -= pxScaledPic.height() + 1000;
                        QFont f;
                        f.setPointSize(20);
                        f.setBold(true);
                        f.setItalic(true);
                        painter.setBrush(QColor(50,205,50));
                        painter.setFont(f);
                        painter.drawText(1700,400,"Fiche partenaire");
                        painter.drawText(400, 1000, "CIN partenaire: ");
                        painter.drawText(2000, 1000,CIN);
                        f.setPointSize(15);
                        f.setBold(true);
                        painter.setFont(f);
                        painter.drawText(100, 1400, "Nom: ");
                        painter.drawText(1000, 1400,nom);
                        painter.drawText(100, 1700, "prenom: ");
                        painter.drawText(1000, 1700,prenom);
                        QFont f1;
                        f1.setPointSize(15);
                        f1.setItalic(true);
                        f1.setBold(true);
                        f1.setUnderline(true);
                        painter.setBrush(QColor(255,0,0));
                        painter.setFont(f1);
                        painter.drawText(3800,5000, "NB");



                           painter.end();
    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Imprimer un profil d'un partenaire"),
                        QObject::tr("Erreur !.\n"
                                    "Veuillez selectionner un partenaire à imprimer .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_Statistique_clicked()
{
    Statisque s;
    s.show();
}
