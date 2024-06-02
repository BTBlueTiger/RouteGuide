#ifndef ROUTINGMODEL_H
#define ROUTINGMODEL_H

#include <QAbstractListModel>

class RoutingModelItem : public QObject {
    Q_OBJECT
public:
    Q_PROPERTY(QString town MEMBER m_town CONSTANT)
    Q_PROPERTY(QString street MEMBER m_street CONSTANT)
    Q_PROPERTY(QString houseNumber MEMBER m_houseNumber CONSTANT)
    Q_PROPERTY(qreal latitude MEMBER m_latitude CONSTANT)
    Q_PROPERTY(qreal longitude MEMBER m_longitude CONSTANT)

    RoutingModelItem(const QString&, const QString&, const QString&, QObject* parent = nullptr);
    RoutingModelItem(const QString&, const QString&, const QString&, const qreal, const qreal, QObject* parent = nullptr);
    ~RoutingModelItem();

    QString getExplicitStop() const;

    QString town() const;

    void setLatitude(const qreal latitude);
    void setLongitude(const qreal longitude);
    void setHouseNumber(const QString& houseNumber);


private:
    QString m_town, m_street, m_houseNumber;
    qreal m_latitude, m_longitude;
};

class RoutingModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QVector<RoutingModelItem*> locations READ locations WRITE setLocations NOTIFY locationsChanged FINAL)

public:
    RoutingModel(QObject* parent = nullptr);
    RoutingModel(QVector<RoutingModelItem*>&, QObject* parent = nullptr);
    ~RoutingModel();

    QString name() const;
    QVector<RoutingModelItem*> locations() const;

    void setName(const QString&);
    void setLocations(const QVector<RoutingModelItem*>&);

private:
    QString m_name;
    QVector<RoutingModelItem*> m_locations;

signals:
    void nameChanged();
    void locationsChanged();

};

#endif // ROUTINGMODEL_H
