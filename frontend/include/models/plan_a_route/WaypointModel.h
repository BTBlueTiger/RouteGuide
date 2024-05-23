#ifndef WAYPOINTMODEL_H
#define WAYPOINTMODEL_H
#include <QAbstractListModel>
#include <QSettings>

class WaypointModelItem {
public:
    WaypointModelItem(const QString &houseNumber);
    QString houseNumber() const;
    void updateHouseNumber(const QString& houseNumber);

private:
    QString m_houseNumber;
};



class WaypointModel : public QAbstractListModel {
Q_OBJECT
public:

    Q_PROPERTY(QString town READ town WRITE setTown NOTIFY townChanged FINAL)

    Q_PROPERTY(QString street READ street WRITE setStreet NOTIFY streetChanged FINAL)

    Q_PROPERTY(QVector<WaypointModelItem> houseNumbers READ houseNumbers WRITE setHouseNumbers NOTIFY houseNumbersChanged FINAL)

    Q_INVOKABLE void append(const QString& houseNumber);

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE void changeItem(int index, const QString& houseNumber, int count = 1);

    Q_INVOKABLE int getLenghtOfList() const;

    Q_INVOKABLE QVariantList qVariantListhouseNumbers() const;
    enum WaypointRoles {
        StreetRole,
        TownRole,
        HouseNumberRole = Qt::UserRole + 1
    };
    WaypointModel(QObject* parent = nullptr);
    ~WaypointModel();

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setTown(const QString& town);
    void setStreet(const QString& street);
    void setHouseNumbers(const QVector<WaypointModelItem>& houseNumbers);


    QString town() const;
    QString street() const;
    QVector<WaypointModelItem> houseNumbers() const;

signals:
    void townChanged(const QString&);
    void streetChanged(const QString&);
    void houseNumbersChanged(const QVector<WaypointModelItem>&);

protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    QVector<WaypointModelItem> m_items;
    QString m_town;
    QString m_street;
};


#endif // WAYPOINTMODEL_H
