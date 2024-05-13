#ifndef PLANAROUTEMODEL_H
#define PLANAROUTEMODEL_H

#include <QAbstractListModel>
#include"PlanARouteModelItem.h"

class PlanARouteModel : public QAbstractListModel {
Q_OBJECT

public:

    Q_INVOKABLE void append(const QString &town, const double latitude, const double longitude);

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE QVariantList getTownsForQML() const;

    enum MyListRoles {
        TownRole = Qt::UserRole + 1
    };

    PlanARouteModel(QObject* parent = nullptr);
    ~PlanARouteModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    void append(PlanARouteModelItem item);
    QVector<PlanARouteModelItem> m_items;
};

#endif // PLANAROUTEMODEL_H
