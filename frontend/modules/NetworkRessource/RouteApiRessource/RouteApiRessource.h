#ifndef ROUTERESSOURCE_H
#define ROUTERESSOURCE_H

#include <QObject>
#include <QQmlEngine>
#include "../AbstractRessource/AbstractRessource.h"

class RouteApiRessource : public AbstractRessource
{
    Q_OBJECT
public:
    explicit RouteApiRessource(QObject *parent = nullptr);


    /**
     * @brief createRoute
     * @param map of the new route containing map details like user groups etc
     * @return if sucess
     */
    Q_INVOKABLE bool createRoute(const QVariantMap&);

};

#endif // ROUTERESSOURCE_H
