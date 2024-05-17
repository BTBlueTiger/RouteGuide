#ifndef PLANAROUTEMODEL_H
#define PLANAROUTEMODEL_H

#include <QAbstractListModel>
#include "WaypointModel.h"


class PlanARouteModel : public QAbstractListModel {
Q_OBJECT

public:

    Q_INVOKABLE void append(WaypointModel& model);

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE QVariantList waypointsForQML() const;

    enum MyListRoles {
        TownRole = Qt::UserRole + 1
    };

    PlanARouteModel(QObject* parent = nullptr);
    ~PlanARouteModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = TownRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    QVector<WaypointModel*> m_items;
};





#endif // PLANAROUTEMODEL_H
