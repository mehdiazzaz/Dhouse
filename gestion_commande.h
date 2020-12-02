#ifndef GESTION_COMMANDE_H
#define GESTION_COMMANDE_H
#include "crud_commandes.h"

#include <QDialog>

namespace Ui {
class gestion_commande;
}

class gestion_commande : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_commande(QWidget *parent = nullptr);
    ~gestion_commande();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::gestion_commande *ui;
     crud_commandes tempcommandes;
};

#endif // GESTION_COMMANDE_H
