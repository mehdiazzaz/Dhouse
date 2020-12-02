#ifndef ORACLEQT_H
#define ORACLEQT_H
#include <QSqlDatabase>


class oracleqt
{
private:
    QSqlDatabase db;
public:
    oracleqt();
    bool create_cnx();
};

#endif // CONNEXION_H
