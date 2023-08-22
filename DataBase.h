#pragma once

#if defined(_WIN64)
#pragma comment(lib, "libmysql.lib")
//#include "mysql.h"
#include <QSqlDatabase>
#elif defined(__linux__)
#include "mysql/mysql.h"
#endif

#include <string>
#include <vector>
#include <memory>
#include <QSqlDatabase>

#include <QVector>
#include <QString>

class DataBase
{
private:
    QSqlDatabase _mysql;
	bool _connection;
	void close();

public:
	DataBase();
	~DataBase();
    bool connect(QString host, unsigned int port, QString dbname, QString user, QString password);
	bool hasConnection();
    QVector<QString> queryResult(QString queryText);
    void executeQueryWithoutResult(QString queryText);
};

