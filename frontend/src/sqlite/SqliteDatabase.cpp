/*
#include "include/sqlite/SqliteDatabase.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

SqliteDatabase::SqliteDatabase(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with Local Database fail";
    }
    else
    {
        qDebug() << "Local Database: connection ok";
    }
}

SqliteDatabase::~SqliteDatabase()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool SqliteDatabase::isOpen() const
{
    return m_db.isOpen();
}

bool SqliteDatabase::createTable(const TableType tableType)
{
    bool success = false;

    QSqlQuery query;
    switch (tableType) {
    case SqliteDatabase::TableType::ROUTES:
        query.prepare("CREATE TABLE routes(id INTEGER PRIMARY KEY AUTOINCREMENT);");
        break;
    case SqliteDatabase::TableType::WAYPOINT:
        query.prepare("CREATE TABLE Waypoints ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "route_id INTEGER,"
        "name TEXT,"
        "latitude REAL,"
        "longitude REAL,"
        "FOREIGN KEY (route_id) REFERENCES Routes(id) ON DELETE CASCADE);");
        break;
    default:
        break;
    }

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table for";
        switch (tableType) {
        case SqliteDatabase::TableType::ROUTES:
            qDebug() << "Routes";
        case SqliteDatabase::TableType::WAYPOINT:
            qDebug() << "WayPoint";
            break;
        default:
            break;
        }
        success = false;
    }

    return success;
}

bool SqliteDatabase::addEntry(const TableType tableType, const QObject& entry)
{
    bool success = true;
    switch (tableType) {
    case SqliteDatabase::TableType::ROUTES:
        try {

        } catch (...) {
        }
        break;
    case SqliteDatabase::TableType::WAYPOINT:

        break;
    default:
        break;
    }
}
*/
