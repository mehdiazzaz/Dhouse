#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
           connect(player,&QMediaPlayer::positionChanged,this, &MainWindow::on_positionchanged);
             connect(player,&QMediaPlayer::durationChanged,this, &MainWindow::on_durationchanged);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_exit_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Dhouse-module_gsetion_des_clients/bon travail et aurevoir.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(2);
        QVideoWidget * VW =new QVideoWidget ;
                  player->setVideoOutput(VW);
                  player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Dhouse-module_gsetion_des_clients/thank.mpg"));
                  VW->setGeometry(350,120,700,500);
                  VW->show();
                  player->setVolume(10);
                  player->play();
                  qDebug() <<player->state();
                  QThread::sleep(5);
                  VW->close();
                  close();

}

void MainWindow::on_pushButton_clicked()
{

    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Dhouse-module_gsetion_des_clients/gestion des clients.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
    gc=new gestion_client(this);
    gc->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMediaPlayer* player;
        player= new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Dhouse-module_gsetion_des_clients/gestion de promotion.mp3"));
            player->play();
            qDebug()<<player->errorString();
            QThread::sleep(1);
    gf=new gestion_produit(this);
    gf->show();
}

//
QMediaPlayer *player;
void MainWindow::on_sliderprogress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_slidervolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_pushButton_4_clicked()
{
    player->setMedia(QUrl("C:/Users/HP/Desktop/Dhouse-module_gsetion_des_clients/la.mp3"));
       player->play();
       qDebug()<<player->errorString();
}
//
void MainWindow::on_pushButton_5_clicked()
{
    player->stop();
}
void MainWindow::on_positionchanged(qint64 position)
{
ui->sliderprogress->setValue(position);
}
void MainWindow::on_durationchanged(qint64 position)
{
ui->sliderprogress->setMaximum(position);
}

void MainWindow::on_pushButton_3_clicked()
{
    gcc=new gestion_commande(this);
    gcc->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    gr=new gestiondereclamation(this);
    gr->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    ga=new gestion_administrateur(this);
    ga->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    gp=new gestion_partenaires(this);
    gp->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    ar=new gestion_arduino (this);
    ar->show();
}
