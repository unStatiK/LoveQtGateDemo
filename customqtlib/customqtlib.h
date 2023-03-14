#ifndef CUSTOMQTLIB_H
#define CUSTOMQTLIB_H

#include "customqtlib_global.h"
#include <QDir>
#include <QFileInfo>
#include <QtSql>

class CustomQtLib
{

public:
    CustomQtLib();
    QSqlDatabase db;
    void init();
    char* get_version();
    QSqlQuery select(const QString sql, QMap<QString, QVariant> params);
};

#endif // CUSTOMQTLIB_H
