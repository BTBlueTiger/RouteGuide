#ifndef NOMINATIMRESSOURCE_H
#define NOMINATIMRESSOURCE_H

#include "AbstractResource.h"
#include "qjsonarray.h"

class NominatimRessource : public AbstractResource
{
Q_OBJECT

public:

    enum ResponseType{
        Success,
        Failed,
        NetworkError
    };
    Q_ENUM(ResponseType)

    Q_PROPERTY(QString search WRITE setSearch NOTIFY searchChanged FINAL)

    NominatimRessource(QObject *parent = nullptr);
    Q_INVOKABLE void searchQ();

    void setSearch(const QString& search);

signals:
    void networkResponse(ResponseType responseType, const QJsonArray& data = QJsonArray());

    void searchChanged();

public slots:
    void networkRequestFinished();

private:

    QString m_search;
};

#endif // NOMINATIMRESSOURCE_H
