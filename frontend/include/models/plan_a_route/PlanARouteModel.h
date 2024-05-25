#ifndef PLANAROUTEMODEL_H
#define PLANAROUTEMODEL_H

#include <QAbstractListModel>
#include "WaypointModel.h"


class PlanARouteModel : public QAbstractListModel {
Q_OBJECT

    Q_PROPERTY(int index READ index CONSTANT)
public:

    Q_INVOKABLE void appendNewWayPointModel(int row);

    Q_INVOKABLE WaypointModel* getModel(int index);

    Q_INVOKABLE void setModel(int index, WaypointModel* model);

    Q_INVOKABLE void remove(int index);

    Q_INVOKABLE QVariantList waypointsForQML() const;

    enum MyListRoles {
        WayPoinModelRole = Qt::UserRole + 1
    };

    PlanARouteModel(QObject* parent = nullptr);
    ~PlanARouteModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = WayPoinModelRole) const override;
    int index() const;

    void setIndex(int index);
    QVector<WaypointModel*> waypointModels() const;

protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    QVector<WaypointModel*> m_items;
    int m_index;

signals:
    void indexChanged(int index);
    void waypointModelChanged(int index);
};





#endif // PLANAROUTEMODEL_H
