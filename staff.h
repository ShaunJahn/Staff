#ifndef STAFF_H
#define STAFF_H

#include <QStringList>
#include <QDate>
#include <QObject>
#include <QMetaEnum>

class Staff : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(StaffType type READ getTypeST WRITE setType)
    Q_ENUMS(StaffType)
public:
    enum StaffType {Permanent, PartTime, Contract};

    Staff();
    Staff(QString n, QDate d, QString t);
    QStringList staffTypes();

private:
    void setName(QString n);
    void setDate(QDate d);
    void setType(QString t);
    void setType(StaffType t);

    QString getName() const;
    QDate getDate() const;
    QString getType() const;
    StaffType getTypeST() const;
    QMetaEnum getMetaEnum() const;
    QString findEnumString(int i) const;
    int findEnumInt(QString str) const;

    QString name;
    QDate birthDate;
    StaffType type;
};

#endif // STAFF_H
