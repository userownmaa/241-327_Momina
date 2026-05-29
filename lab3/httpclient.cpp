#include "httpclient.h"
#include <QJsonDocument>
#include <QSslConfiguration>
#include <QSslSocket>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

HttpClient::HttpClient(QObject* parent)
    : QObject(parent), m_manager(new QNetworkAccessManager(this))
{
    m_baseUrl = QUrl("https://localhost:8443/api/medicine/");
    QSslConfiguration config = QSslConfiguration::defaultConfiguration(); //берём текущую конфигурацию
    config.setPeerVerifyMode(QSslSocket::VerifyNone); //отключаем проверку сертификата (VerifyNone) – это необходимо для самоподписанного сертификата, иначе соединение будет отвергнуто
    QSslConfiguration::setDefaultConfiguration(config); //устанавливаем изменённую конфигурацию как глобальную по умолчанию
}

HttpClient::~HttpClient() {}

HttpClient& HttpClient::instance() //Реализация Singleton – статическая локальная переменная instance создаётся при первом вызове и живёт до конца программы. Возвращается ссылка на неё.
{
    static HttpClient instance;
    return instance;
}

void HttpClient::sendRequest(const QUrl& url, const QString& method, const QByteArray& body)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = nullptr;
    if (method == "GET") reply = m_manager->get(request);
    else if (method == "POST") reply = m_manager->post(request, body);
    else if (method == "PUT") reply = m_manager->put(request, body);
    else if (method == "DELETE") reply = m_manager->deleteResource(request);
    else return;

    //cоединяет сигнал finished от reply со слотом onReplyFinished. когда ответ придёт, будет вызван слот
    connect(reply, &QNetworkReply::finished, this, &HttpClient::onReplyFinished);
}

void HttpClient::onReplyFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError)
        emit requestCompleted(reply->readAll());
    else
        emit requestError(reply->errorString());

    reply->deleteLater();
}

void HttpClient::getMedicineList() { sendRequest(m_baseUrl, "GET"); }

void HttpClient::getMedicineById(int id)
{
    QUrl url(m_baseUrl.toString() + QString::number(id) + "/");  //формируем URL вида /api/medicine/{id}/
    sendRequest(url, "GET");
}

void HttpClient::createMedicine(const Medicine& med)
{
    QJsonDocument doc(med.toJson());
    sendRequest(m_baseUrl, "POST", doc.toJson());
//    qDebug() << "Sending price:" << med.price();
}

void HttpClient::updateMedicine(int id, const Medicine& med)
{
    QUrl url(m_baseUrl.toString() + QString::number(id) + "/");
    QJsonDocument doc(med.toJson());
    sendRequest(url, "PUT", doc.toJson());
//    qDebug() << "Sending price:" << med.price();
}

void HttpClient::deleteMedicine(int id)
{
    QUrl url(m_baseUrl.toString() + QString::number(id) + "/");
    sendRequest(url, "DELETE");
}
