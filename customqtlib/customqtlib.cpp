#include "customqtlib.h"


CustomQtLib::CustomQtLib()
{
    int argc;
    char *argv[] = {'\0'};
    QCoreApplication a(argc, argv);
}

void CustomQtLib::init()
{    
    QString dataPath = QDir::currentPath() + "/data/";
    if(!QDir(dataPath).exists()){
        QDir().mkdir(dataPath);
    }

    QString dbPath = dataPath + "duplex.db";

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(dbPath);    

    QFileInfo checkFile(dbPath);

    if (!checkFile.exists()) {
        this->db.open();
        QSqlQuery query_pragma_fk("PRAGMA foreign_keys = ON;");
        query_pragma_fk.exec();

        QSqlQuery query_pragma_enc("PRAGMA encoding = \"UTF-8\";");
        query_pragma_enc.exec();

        QSqlQuery query_pragma_sync("PRAGMA synchronous=FULL;");
        query_pragma_sync.exec();

        this->db.transaction();
        QSqlQuery bootstrap;

        bootstrap.prepare("CREATE TABLE meta("
                            "   db_version INTEGER,"
                            "   description TEXT"
                            ");");
        bootstrap.exec();
        this->db.commit();


        this->db.transaction();
        QSqlQuery meta;
        meta.prepare("INSERT INTO meta (db_version, description) VALUES (:version, :desc)");
        meta.bindValue(":version", "1448");
        meta.bindValue(":desc", "Test description");
        meta.exec();
        this->db.commit();

    } else {
        this->db.open();
    }
}

QSqlQuery CustomQtLib::select(const QString sql, QMap<QString, QVariant> params)
{
    QSqlQuery query;
    query.prepare(sql);

    QMap<QString, QVariant>::iterator i;
    for (i = params.begin(); i != params.end(); ++i){
        query.bindValue(i.key(), i.value());
    }

    query.exec();
    return query;
}

char* CustomQtLib::get_version()
{
    QString qtVersion = QString("Qt version: ") + QT_VERSION_STR;
    std::string stdVersion = qtVersion.toStdString();
    char *version = new char[strlen(stdVersion.c_str()) + 1];
    strcpy(version, stdVersion.c_str());
    return version;
}
