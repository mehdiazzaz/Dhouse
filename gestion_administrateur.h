#ifndef GESTION_ADMINISTRATEUR_H
#define GESTION_ADMINISTRATEUR_H

#include <QDialog>
#include "administrateur.h"
#include "agent.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include "smtp.h"
#include <QFileDialog>

namespace Ui {
class gestion_administrateur;
}

class gestion_administrateur : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_administrateur(QWidget *parent = nullptr);
    ~gestion_administrateur();


        QSortFilterProxyModel *proxy_Administrateur,*proxy_Agent;

        void afficher();

private slots:
    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_editer_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_ajouteragent_clicked();

    void on_pushButton_editeragent_clicked();

    void on_pushButton_suppagent_clicked();



    void on_comboBox_agent_currentIndexChanged(int index);

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_comboBox_adm_currentIndexChanged(int index);

    void on_lineEdit_id3_textChanged(const QString &arg1);

    void sendMail();
    void mailSent(QString);
    void browse();


private:
    Ui::gestion_administrateur *ui;

    Administrateur Etmp;
    Agent  Atmp;

    int selected_Agent=0;
    int selected_Administrateur=0;
    QStringList files;
};

#endif // GESTION_ADMINISTRATEUR_H
