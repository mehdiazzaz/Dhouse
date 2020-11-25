#ifndef GESTION_PRODUIT_H
#define GESTION_PRODUIT_H

#include <QDialog>
#include <QMessageBox>
#include "crud_produit.h"
#include <QMediaPlayer>
namespace Ui {
class gestion_produit;
}

class gestion_produit : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_produit(QWidget *parent = nullptr);
    ~gestion_produit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:
    Ui::gestion_produit *ui;
    crud_produit tempproduit;
    QMediaPlayer* player;
};

#endif // GESTION_PRODUIT_H
