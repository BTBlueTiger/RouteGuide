#ifndef WAYPOINTMODEL_H
#define WAYPOINTMODEL_H
#include <QAbstractListModel>
#include <QSettings>

class WaypointModel : public QAbstractListModel {
Q_OBJECT
public:

    Q_PROPERTY(QString town READ town WRITE setTown NOTIFY townChanged FINAL)

    Q_PROPERTY(QString street READ street WRITE setStreet NOTIFY streetChanged FINAL)

    Q_PROPERTY(QStringList houseNumbers READ houseNumbers WRITE setHouseNumbers NOTIFY houseNumbersChanged FINAL)

    Q_INVOKABLE void append();

    Q_INVOKABLE void removeEmptyStops();

    Q_INVOKABLE void remove(int);


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
    void setHouseNumbers(const QStringList& houseNumbers);


    QString town() const;
    QString street() const;
    QStringList houseNumbers() const;

signals:
    void townChanged(const QString&);
    void streetChanged(const QString&);
    void houseNumbersChanged() const;

protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    QStringList m_items;
    QString m_town;
    QString m_street;
};


#endif // WAYPOINTMODEL_H
