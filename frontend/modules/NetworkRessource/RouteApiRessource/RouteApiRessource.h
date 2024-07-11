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

    /**
     * @brief getRoute gives a jsonarray of a certain group type, like hiker
     * @param group the "id" int of the group
     * @return a jsonarray of the routes
     */
    Q_INVOKABLE QVariantList getRoutes(int group);

    /**
     * @brief getFakeRoutes simple Fake Route composition to program functionality
     * @return a jsonarray of 2 or 3 routes
     */
    Q_INVOKABLE QVariantList getFakeRoutes();

};

#endif // ROUTERESSOURCE_H
