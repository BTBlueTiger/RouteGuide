#ifndef PLANAROUTEMODELITEM_H
#define PLANAROUTEMODELITEM_H

#include <QObject>

class PlanARouteModelItem {


public:

    PlanARouteModelItem(const QString& town, const double latitude, const double longitude);
    QString town() const;
    double latitude() const;
    double longitude() const;
public slots:

private:
    QString m_town;
    double m_latitude, m_longitude;
};

#endif // PLANAROUTEMODELITEM_H
