/*
#ifndef SQLITEDATABASE_H
#define SQLITEDATABASE_H

#include <QSqlDatabase>

class SqliteDatabase
{
public:

    enum TableType {
        ROUTES,
        WAYPOINT
    };

    SqliteDatabase(const QString& path);

    ~SqliteDatabase();

    bool isOpen() const;

    bool createTable(const TableType);

    bool addEntry(const TableType, const QObject& entry);

private:
    QSqlDatabase m_db;
};

#endif // SQLITEDATABASE_H
*/
