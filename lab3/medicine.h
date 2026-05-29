#ifndef MEDICINE_H
#define MEDICINE_H

#include <QString>
#include <QDate>
#include <QJsonObject>

class Medicine
{
public:
    Medicine();
    Medicine(int id, const QString& name, int price, int quantity,
             const QDate& expirationDate, const QString& manufacturer,
             bool requiresPrescription, const QString& description);
    //Геттеры
    int id() const;
    QString name() const;
    int price() const;
    int quantityInStock() const;
    QDate expirationDate() const;
    QString manufacturer() const;
    bool requiresPrescription() const;
    QString description() const;
    //Сеттеры
    void setId(int newId);
    void setName(const QString& newName);
    void setPrice(double newPrice);
    void setQuantityInStock(int newQuantity);
    void setExpirationDate(const QDate& newDate);
    void setManufacturer(const QString& newManufacturer);
    void setRequiresPrescription(bool newReq);
    void setDescription(const QString& newDesc);

    //сериализация
    QJsonObject toJson() const;
    //десериализация
    static Medicine fromJson(const QJsonObject& obj);

private:
    int m_id;
    QString m_name;
    int m_price;
    int m_quantityInStock;
    QDate m_expirationDate;
    QString m_manufacturer;
    bool m_requiresPrescription;
    QString m_description;
};

#endif // MEDICINE_H
