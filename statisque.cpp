#include "statisque.h"
#include "ui_statisque.h"

Statisque::Statisque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statisque)
{
    ui->setupUi(this);
}

Statisque::~Statisque()
{
    delete ui;
}
