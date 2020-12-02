#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_commande.h"
#include"gestiondereclamation.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_reclamation_clicked();

private:
    Ui::MainWindow *ui;
    gestion_commande *gc;
    gestiondereclamation *gr;
};
#endif // MAINWINDOW_H
