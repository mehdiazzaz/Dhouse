#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_client.h"
#include "gestion_produit.h"
#include "gestion_commande.h"
#include"gestiondereclamation.h"
#include "gestion_administrateur.h"
#include "gestion_partenaires.h"
#include "gestion_arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//
private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    //
    void on_sliderprogress_sliderMoved(int position);

        void on_slidervolume_sliderMoved(int position);

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_positionchanged(qint64 position);

        void on_durationchanged(qint64 position);
        //

        void on_pushButton_3_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

        void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    gestion_client *gc;
    gestion_produit *gf;
    gestion_commande *gcc;
    gestiondereclamation *gr;
    gestion_administrateur *ga;
    gestion_partenaires *gp;
    QMediaPlayer *player;
    gestion_arduino *ar;


};
#endif // MAINWINDOW_H
