#include "mainwindow.h"
#include "connection.h"
#include "gestion_administrateur.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection C;
    bool test=C.ouvrirConnection();
    gestion_administrateur g;

    if(test)
      //qDebug()<<"connexion réussite";
    g.show();
      QMessageBox::information(nullptr,QObject::tr("database is open"),
               QObject::tr("connexion successful\n"
                           "click Ok to exit"),QMessageBox::Ok);

  /*  else{

      //qDebug() <<"eureurde connexion" ;
        QMessageBox::critical(nullptr,QObject::tr("database is open"),
                 QObject::tr("connexion failed\n"
                             "click Cancel to exit"),QMessageBox::Cancel);}*/
    return a.exec();
}
