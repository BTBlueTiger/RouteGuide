#ifndef WAYPOINTMODEL_H
#define WAYPOINTMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "include/connections/ResponseType.h"
#include "include/models/AbstractModel.h"
#include "include/models/waypoint/WaypointModelItem.h"

namespace Waypoint
{
    class WaypointModel : public QAbstractListModel, public AbstractModel {
        Q_OBJECT
    public:

        Q_INVOKABLE void setJsonData(const QJsonArray& array);
        Q_INVOKABLE void remove(int);
        Q_INVOKABLE void appendModelItem(WaypointModelItem*);
        Q_INVOKABLE WaypointModelItem* getModelItem(int index);
        Q_INVOKABLE QList<QGeoCoordinate> getCoordinates() const;


        enum WaypointRoles {
            DisplayNameRole = Qt::UserRole + 1,
            CoordinateRole
        };
        WaypointModel(QObject* parent = nullptr) : QAbstractListModel(parent) {};
        ~WaypointModel();

        bool setData(const QModelIndex &index, const QVariant &value, int role) override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        bool isConnectedToLocationRessource() const;
        void setIsConnectedToLocationRessource();

    protected:
        QHash<int, QByteArray> roleNames() const override;

    private:
        QVector<WaypointModelItem*> m_waypointModelItems;
        bool m_isConnected;

    public slots:
        void onNominatimRessourceResponse(ResponseType responseType, const QJsonArray& data);
    };
}

#endif // WAYPOINTMODEL_H
