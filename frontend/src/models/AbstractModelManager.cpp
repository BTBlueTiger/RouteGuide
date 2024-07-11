#include  "include/models/AbstractModelManager.h"


AbstractModelManager::AbstractModelManager(QObject* parent) : QObject(parent)
{

}

AbstractModelManager::~AbstractModelManager()
{
    qDeleteAll(m_models);
    m_models.clear();
}


AbstractModel* AbstractModelManager::createModel(const QString& modelName)
{
    AbstractModel* model = new AbstractModel;
    m_models[modelName] = model;
    return model;
}

AbstractModel* AbstractModelManager::getModel(const QString& modelName) const
{
    if(m_models.contains(modelName))
    {
        return m_models[modelName];
    }
    return nullptr;
}
