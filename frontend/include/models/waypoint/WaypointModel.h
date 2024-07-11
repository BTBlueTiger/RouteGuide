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

        Q_PROPERTY(QVariantList waypointInformations READ waypointInformations NOTIFY waypointInformationsChanged)
        Q_PROPERTY(QVariantList coordinates READ coordinates NOTIFY coordinatesChanged)
        Q_INVOKABLE void clearCoordinates();


        enum WaypointRoles {
            DisplayNameRole = Qt::UserRole + 1,
            CoordinateRole
        };
        WaypointModel(QObject* parent = nullptr) : QAbstractListModel(parent) {};
        ~WaypointModel();

        bool setData(const QModelIndex &index, const QVariant &value, int role) override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        /**
         * @brief // All coordinates + displayname in this model, simply the waypointmodelitem as QVariant
         * @return All coordinates in this model
         */
        QVariantList waypointInformations() const;
        /**
         * @brief All coordinates in this model
         * @return All coordinates in this model
         */
        QVariantList coordinates() const;

        bool isConnectedToLocationRessource() const;
        void setIsConnectedToLocationRessource();

    protected:
        QHash<int, QByteArray> roleNames() const override;

    private:

        // All WaypointModelItems
        QVector<WaypointModelItem*> m_waypointModelItems;
        // All coordinates + displayname in this model
        QVariantList m_waypointInformations;
        // All coordinates in this model
        QVariantList m_coordinates;
        bool m_isConnected;

    signals:
        void waypointInformationsChanged();
        void coordinatesChanged();

    public slots:
        void onNominatimRessourceResponse(ResponseType responseType, const QJsonArray& data);
    };
}

#endif // WAYPOINTMODEL_H
