#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "oracleqt.h"
#include <QThread>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include "login.h"


int main(int argc, char *argv[])
{
     QApplication a(argc, argv);

       QMediaPlayer * player = new QMediaPlayer;
           QVideoWidget * VW =new QVideoWidget ;
           player->setVideoOutput(VW);
           player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/aa.mpg"));
           VW->setGeometry(320,120,700,500);
           VW->show();
           player->play();
           qDebug() <<player->state();
           QThread::sleep(9);
           VW->close();

        player= new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/bienvenu.mp3"));
           player->play();
          qDebug()<<player->errorString();
        // QThread::sleep(1);

       //   QMediaPlaylist *playlist = new QMediaPlaylist();
       //   playlist->addMedia(QUrl("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/la.mp3"));
        //   playlist->setPlaybackMode(QMediaPlaylist::Loop);
       //    QMediaPlayer *music = new QMediaPlayer();
       // music->setPlaylist(playlist);
      //  music->setVolume(0);
        //music->play();

    MainWindow w;
    oracleqt c;
    bool test=c.create_cnx();
    //w.show();
    login l;
        l.show();
        QObject::connect(&l,&login::sig,&w,&MainWindow::show);

    if(test)
   {


        qDebug() <<"connexion etablie";
                }
                else
                {

                    qDebug() <<"ereur de connexion";
                }


//


    return a.exec();
}
