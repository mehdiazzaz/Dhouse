#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

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
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/bon travail et aurevoir.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(2);
    close();
}

void MainWindow::on_pushButton_clicked()
{

    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/gestion des clients.mp3"));
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
        player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/gestion de promotion.mp3"));
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
    player->setMedia(QUrl("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/la.mp3"));
       player->play();
       qDebug()<<player->errorString();
}

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
