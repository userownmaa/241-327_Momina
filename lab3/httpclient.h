#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>  //класс для отправки сетевых запросов
#include <QNetworkReply>   // класс, представляющий ответ на запрос
#include "medicine.h"

class HttpClient : public QObject
{
    Q_OBJECT

public:
    static HttpClient& instance();    //статический метод – точка доступа к единственному экземпляру Singleton. Возвращает ссылку на объект

    void getMedicineList();
    void getMedicineById(int id);
    void createMedicine(const Medicine& med);
    void updateMedicine(int id, const Medicine& med);
    void deleteMedicine(int id);

signals:    //сигналы подключены к слотам MainWindow::handleResponse и MainWindow::handleError.
    void requestCompleted(const QByteArray& responseData);
    void requestError(const QString& errorString);

private slots:  //вызывается, когда QNetworkReply завершается
    void onReplyFinished();

private:
    explicit HttpClient(QObject* parent = nullptr);
    ~HttpClient();

    //копирование и оператор присваивания удалены
    HttpClient(const HttpClient&) = delete;
    HttpClient& operator=(const HttpClient&) = delete;

    QNetworkAccessManager* m_manager;    //указатель на QNetworkAccessManager; через него выполняются все запросы
    QUrl m_baseUrl;
    //внутренний метод, который делает реальный HTTP-запрос, добавляет заголовки, соединяет сигнал finished со слотом onReplyFinished
    void sendRequest(const QUrl& url, const QString& method,
                     const QByteArray& body = QByteArray());
};

#endif // HTTPCLIENT_H
