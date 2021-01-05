#ifndef GESTION_ARDUINO_H
#define GESTION_ARDUINO_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class gestion_arduino;
}

class gestion_arduino : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_arduino(QWidget *parent = nullptr);
    ~gestion_arduino();

private slots:
    void up_data();

    void on_on_clicked();

    void on_off_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gestion_arduino *ui;
     QByteArray data;
    Arduino A;
};

#endif // GESTION_ARDUINO_H
