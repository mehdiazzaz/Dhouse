#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "partenaire.h"
#include "publicite.h"

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
    Partenaire tmppartenaire;
    Publicite tmppublicite;
    QVBoxLayout* mainLayout;
};
#endif // MAINWINDOW_H
