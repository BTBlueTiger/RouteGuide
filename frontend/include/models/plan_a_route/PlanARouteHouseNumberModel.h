#ifndef PLANAROUTEHOUSENUMBERMODEL_H
#define PLANAROUTEHOUSENUMBERMODEL_H
#include <QAbstractListModel>
#include <QSettings>

class PlanARouteHouseNumberModelItem {
public:
    PlanARouteHouseNumberModelItem(const QString &houseNumber);
    QString houseNumber() const;
    void updateHouseNumber(const QString& houseNumber);

private:
    QString m_houseNumber;
};



class PlanARouteHouseNumberModel : public QAbstractListModel {
Q_OBJECT
public:
    Q_INVOKABLE void append(const QString& houseNumber);

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE void changeItem(int index, const QString& houseNumber, int count = 1);

    Q_INVOKABLE int getLenghtOfList() const;

    Q_INVOKABLE QVariantList qVariantListhouseNumbers() const;

    Q_INVOKABLE void setQSetttings(const QString& town, const QString& street);

    enum MyListRoles {
        HouseNumberRole = Qt::UserRole + 1
    };
    PlanARouteHouseNumberModel(QObject* parent = nullptr);
    ~PlanARouteHouseNumberModel();

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    QVector<PlanARouteHouseNumberModelItem> m_items;
};


#endif // PLANAROUTEHOUSENUMBERMODEL_H
