#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_connect_clicked();
   //
    void on_pushButton_2_clicked();

signals:
    void sig();
    //
private:
    Ui::login *ui;
    //
    MainWindow *m;
    //
    //
};

#endif // LOGIN_H
