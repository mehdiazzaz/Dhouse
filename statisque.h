#ifndef STATISQUE_H
#define STATISQUE_H

#include <QDialog>

namespace Ui {
class Statisque;
}

class Statisque : public QDialog
{
    Q_OBJECT

public:
    explicit Statisque(QWidget *parent = nullptr);
    ~Statisque();

private:
    Ui::Statisque *ui;
};

#endif // STATISQUE_H
