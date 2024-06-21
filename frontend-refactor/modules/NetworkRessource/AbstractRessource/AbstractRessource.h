#ifndef ABSTRACTRESSOURCE_H
#define ABSTRACTRESSOURCE_H

#include <QObject>

#include <QFuture>
#include <QPromise>
#include <QNetworkAccessManager>
#include <QNetworkRequestFactory>
#include <QUrl>
#include <QHttpHeaders>

/**
 * @brief The AbstractRessource class handles HTTP calls.
 *
 * This class provides an interface for making HTTP requests such as GET and POST.
 * It utilizes `QNetworkAccessManager` for network operations and can convert `QVariantMap` to `QByteArray`.
 */
class AbstractRessource : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the AbstractRessource class.
     * @param parent The parent QObject, defaults to nullptr.
     */
    explicit AbstractRessource(QObject *parent = nullptr);

    /**
     * @brief Destructor for the AbstractRessource class.
     */
    virtual ~AbstractRessource() = default;

    /**
     * @brief Sets the network access manager.
     * @param manager A shared pointer to a QNetworkAccessManager.
     */
    void setAccessManager(std::shared_ptr<QNetworkAccessManager> manager);

    /**
     * @brief Sets the service API request factory.
     * @param api A shared pointer to a QNetworkRequestFactory.
     */
    void setServiceApi(std::shared_ptr<QNetworkRequestFactory> api);

    /**
     * @brief Sets the service URL.
     * @param url A shared pointer to a QUrl.
     */
    void setServiceURL(std::shared_ptr<QUrl> url);

    /**
     * @brief Sets the HTTP headers.
     * @param headers A shared pointer to a QHttpHeaders.
     */
    void setHttpHeaders(std::shared_ptr<QHttpHeaders> headers);

    /**
     * @brief Converts a QVariantMap to QByteArray.
     * @param data The QVariantMap to convert.
     * @return A unique pointer to the resulting QByteArray.
     */
    std::unique_ptr<QByteArray> qVariantMapToQByteArray(const QVariantMap& data);

    /**
     * @brief Sends a POST request.
     * @param data The data to send in the POST request.
     * @param request The QNetworkRequest to send.
     * @return A pointer to the QNetworkReply object for the request.
     */
    QNetworkReply* postRequest(const QByteArray& data, const QNetworkRequest& request);

    /**
     * @brief Sends a GET request.
     * @param request The QNetworkRequest to send.
     * @return A pointer to the QNetworkReply object for the request.
     */
    QNetworkReply* getRequest(const QNetworkRequest& request);

protected:
    std::shared_ptr<QNetworkAccessManager> m_manager;  ///< Network access manager for handling requests.
    std::shared_ptr<QNetworkRequestFactory> m_api;     ///< Factory for creating network requests.
    std::shared_ptr<QUrl> m_url;                       ///< Service URL.
    std::shared_ptr<QHttpHeaders> m_headers;           ///< HTTP headers for requests.

private:
    int checkedSharedRessources() const;

};


#endif // ABSTRACTRESSOURCE_H
