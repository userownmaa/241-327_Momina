#include "medicine.h"
#include <QLocale>
#include <QJsonObject>   //класс, представляющий JSON-объект

Medicine::Medicine()   //инициализирует все поля значениями по умолчанию
    : m_id(-1), m_price(0.0), m_quantityInStock(0), m_requiresPrescription(false)
{}

Medicine::Medicine(int id, const QString& name, int price, int quantity, //инициализирует все поля переданными значениями
                   const QDate& expirationDate, const QString& manufacturer,
                   bool requiresPrescription, const QString& description)
    : m_id(id), m_name(name), m_price(price), m_quantityInStock(quantity),
      m_expirationDate(expirationDate), m_manufacturer(manufacturer),
      m_requiresPrescription(requiresPrescription), m_description(description)
{}

//Геттеры
int Medicine::id() const { return m_id; }
QString Medicine::name() const { return m_name; }
int Medicine::price() const { return m_price; }
int Medicine::quantityInStock() const { return m_quantityInStock; }
QDate Medicine::expirationDate() const { return m_expirationDate; }
QString Medicine::manufacturer() const { return m_manufacturer; }
bool Medicine::requiresPrescription() const { return m_requiresPrescription; }
QString Medicine::description() const { return m_description; }
//Сеттеры
void Medicine::setId(int newId) { m_id = newId; }
void Medicine::setName(const QString& newName) { m_name = newName; }
void Medicine::setPrice(double newPrice) { m_price = newPrice; }
void Medicine::setQuantityInStock(int newQuantity) { m_quantityInStock = newQuantity; }
void Medicine::setExpirationDate(const QDate& newDate) { m_expirationDate = newDate; }
void Medicine::setManufacturer(const QString& newManufacturer) { m_manufacturer = newManufacturer; }
void Medicine::setRequiresPrescription(bool newReq) { m_requiresPrescription = newReq; }
void Medicine::setDescription(const QString& newDesc) { m_description = newDesc; }

//cериализация
QJsonObject Medicine::toJson() const
{
    QJsonObject obj;
    if (m_id != -1) obj["id"] = m_id;
    obj["name"] = m_name;
    obj["price"] = m_price;
    obj["quantity_in_stock"] = m_quantityInStock;
    obj["expiration_date"] = m_expirationDate.toString("yyyy-MM-dd");
    obj["manufacturer"] = m_manufacturer;
    obj["requires_prescription"] = m_requiresPrescription;
    obj["description"] = m_description;
    return obj;
}
//десериализация
Medicine Medicine::fromJson(const QJsonObject& obj)
{
    Medicine med;
    med.setId(obj["id"].toInt(-1));
    med.setName(obj["name"].toString());
    bool ok;
    double price = QLocale::c().toDouble(obj["price"].toVariant().toString(), &ok);
    med.setPrice(ok ? price : 0.0);
    med.setQuantityInStock(obj["quantity_in_stock"].toInt());
    med.setExpirationDate(QDate::fromString(obj["expiration_date"].toString(), "yyyy-MM-dd"));
    med.setManufacturer(obj["manufacturer"].toString());
    med.setRequiresPrescription(obj["requires_prescription"].toBool());
    med.setDescription(obj["description"].toString());
    return med;
}
