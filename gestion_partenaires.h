#ifndef GESTION_PARTENAIRES_H
#define GESTION_PARTENAIRES_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "partenaire.h"
#include "publicite.h"
#include <QVBoxLayout>

namespace Ui {
class gestion_partenaires;
}

class gestion_partenaires : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_partenaires(QWidget *parent = nullptr);
    ~gestion_partenaires();


private slots:
    void on_pb_ajouterPart_2_clicked();

    void on_pb_supprimerPart_2_clicked();

    void on_pb_modifierPart_2_clicked();

    void on_ch_nom_2_clicked();

    void on_trier_cin_2_clicked();

    void on_pb_ajouterPub_2_clicked();

    void on_trier_id_2_clicked();

    void on_pushButton_Statistique_clicked();

    void on_pb_supprimerPub_2_clicked();

    void on_pb_modifierPub_2_clicked();

    void on_comboPubsupp_2_currentIndexChanged(const QString &arg1);

    void on_comboFmodif_2_currentIndexChanged(const QString &arg1);

    void on_combo_trie_rech_2_currentIndexChanged(const QString &arg1);

    void on_comboCINsupp_2_currentIndexChanged(const QString &arg1);

    void on_comboCINmodif_2_currentIndexChanged(const QString &arg1);

    void on_combo_line_2_windowIconTextChanged(const QString &iconText);

private:
    Ui::gestion_partenaires *ui;
    Partenaire tmppartenaire;
    Publicite tmppublicite;
    QVBoxLayout* mainLayout;
};
#endif // MAINWINDOW_H
