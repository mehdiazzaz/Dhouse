#include "gestion_arduino.h"
#include "ui_gestion_arduino.h"
#include <QDebug>
#include <QString>

gestion_arduino::gestion_arduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_arduino)
{
    ui->setupUi(this);
    int ret =A.connect_arduino();
        switch(ret){
        case(0):qDebug()<<"arduino is available and connect to : " <<A.getarduino_port_name();
                break;
        case(1):qDebug()<<"arduino is available but not connected to : "<<A.getarduino_port_name();
                break;
        case(-1):qDebug()<<"arduino in not available";
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(up_data()));


}

gestion_arduino::~gestion_arduino()
{
    delete ui;
}
void gestion_arduino::up_data()
{
    data=A.read_from_arduino();
    if(data=="1")
        ui->up_data->setText("on");
    else if (data=="0")
        ui->up_data->setText("off");
}

void gestion_arduino::on_on_clicked()
{
    A.write_to_arduino("1");
}

void gestion_arduino::on_off_clicked()
{
    A.write_to_arduino("0");
}

void gestion_arduino::on_pushButton_3_clicked()
{
    close();
}
