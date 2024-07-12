#ifndef ABSTRACTMODELMANAGER_H
#define ABSTRACTMODELMANAGER_H

#include <QObject>
#include <QMap>

#include "AbstractModel.h"


class AbstractModelManager : public QObject {
    Q_OBJECT

public:

    AbstractModelManager(QObject* parent = nullptr);
    ~AbstractModelManager();

    virtual Q_INVOKABLE AbstractModel* createModel(const QString& model) = 0;
    virtual Q_INVOKABLE AbstractModel* getModel(const QString& modelName) const = 0;

protected:
    QMap<QString, AbstractModel*> m_models;

};



#endif // ABSTRACTMODELMANAGER_H
