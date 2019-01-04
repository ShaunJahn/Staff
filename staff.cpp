#include "staff.h"
#include <QMetaProperty>

Staff::Staff()
{
}

Staff::Staff(QString n, QDate d, QString t): name(n), birthDate(d)
{
    type = Staff::StaffType(findEnumInt(t));
}

void Staff::setName(QString n)
{
    name = n;
}

void Staff::setDate(QDate d)
{
    birthDate = d;
}

void Staff::setType(QString t)
{
    type = Staff::StaffType(findEnumInt(t));
}

void Staff::setType(StaffType t)
{
    type = t;
}

QString Staff::getName() const
{
    return name;
}

QDate Staff::getDate() const
{
    return birthDate;
}

QString Staff::getType() const
{
    QString t = findEnumString(type);
    return t;
}

Staff::StaffType Staff::getTypeST() const
{
    return type;
}

QStringList Staff::staffTypes()
{
    QStringList list;
    QMetaEnum me = this->getMetaEnum();
    for (int i=0; i<me.keyCount(); i++)
        list << QString(me.valueToKey(i));
    return list;
}

QMetaEnum Staff::getMetaEnum() const
{
    const QMetaObject *meta = this->metaObject();
    const QMetaEnum metaEnum = meta->enumerator(0); // get meta-data on the first enum in the object
    return metaEnum;
}

QString Staff::findEnumString(int i) const
{
    QMetaEnum me = this->getMetaEnum();
    return QString(me.valueToKey(i));
}
int Staff::findEnumInt(QString str) const
{
    QMetaEnum me = this->getMetaEnum();
    return me.keysToValue(str.toLatin1());
}

