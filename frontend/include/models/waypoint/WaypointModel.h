#ifndef WAYPOINTMODEL_H
#define WAYPOINTMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "include/connections/NominatimRessource.h"
#include "include/models/waypoint/WaypointModelItem.h"

namespace Waypoint
{
    class WaypointModel : public QAbstractListModel {
        Q_OBJECT
    public:

        Q_INVOKABLE void setJsonData(const QJsonArray& array);
        Q_INVOKABLE void remove(int);
        Q_INVOKABLE void appendModelItem(WaypointModelItem*);
        Q_INVOKABLE WaypointModelItem* getModelItem(int index);


        enum WaypointRoles {
            DisplayNameRole = Qt::UserRole + 1,
            CoordinateRole
        };
        WaypointModel(QObject* parent = nullptr) : QAbstractListModel(parent) {};
        ~WaypointModel();

        bool setData(const QModelIndex &index, const QVariant &value, int role) override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


        QVector<WaypointModelItem*> waypointModelItems();

    protected:
        QHash<int, QByteArray> roleNames() const override;

    private:
        QVector<WaypointModelItem*> m_waypointModelItems;

    public slots:
        void onNominatimRessourceResponse(NominatimRessource::ResponseType responseType, const QJsonArray& data);
    };
}

#endif // WAYPOINTMODEL_H
