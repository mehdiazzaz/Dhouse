#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestiondereclamation.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    gc=new gestion_commande(this);
    gc->show();
}


void MainWindow::on_pushButton_reclamation_clicked()
{
    gr=new gestiondereclamation(this);
    gr->show();
}
