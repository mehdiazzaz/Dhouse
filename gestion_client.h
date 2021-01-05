#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H

#include <QDialog>
#include "crud_client.h"
#include <QMessageBox>
#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class gestion_client;
}

class gestion_client : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_client(QWidget *parent = nullptr);
    ~gestion_client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_ajoute_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modifer_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_impression_client_clicked();

    void on_pushButton_ajouter_re_clicked();

    void on_pushButton_rechercher_2_clicked();

    void on_pushButton_rechercher_3_clicked();

    void on_pushButton_rechercher_4_clicked();
//
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::gestion_client *ui;
     crud_client tempclient;
     QMediaPlayer* player;
};

#endif // GESTION_CLIENT_H
