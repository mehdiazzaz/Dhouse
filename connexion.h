#ifndef CONNECTER_H
#define CONNECTER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
//
class connecter
{
public:
    connecter();
    bool creatconnect();
};

#endif // CONNECTER_H
