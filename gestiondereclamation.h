#ifndef GESTIONDERECLAMATION_H
#define GESTIONDERECLAMATION_H
#include <QDialog>
#include <crud_reclamation.h>

namespace Ui {
class gestiondereclamation;
}

class gestiondereclamation : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondereclamation(QWidget *parent = nullptr);
    ~gestiondereclamation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_trierid_reclamation_clicked();

    void on_triernom_reclamation_clicked();

    void on_triertype_reclamation_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::gestiondereclamation *ui;
    crud_reclamation tempreclamation;
};

#endif // GESTIONDERECLAMATION_H
