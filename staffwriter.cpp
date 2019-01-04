#include "staffwriter.h"
#include <QFile>
#include <QTextStream>
#include <QMetaObject>
#include <QMetaProperty>

StaffWriter::StaffWriter()
{
}

bool StaffWriter::writeToFile(Staff *s) const
{
    QFile file("staffFile.txt");
    if (!file.open(QIODevice::Append))
        return false;
    QTextStream toFile(&file);

    const QMetaObject *meta = s->metaObject();
    QString result;

    Staff temp;
    QStringList enumNames = temp.staffTypes(); // to get enum types

    for (int count=meta->propertyOffset(); count<meta->propertyCount(); count++)
    {
        const QMetaProperty prop = meta->property(count);
        QString name = prop.name();
        QVariant value = prop.read(s);
        QString val = value.toString();
        if (prop.isEnumType())
            val = enumNames.at(val.toInt());
        result += QString(name + ": " + val + "; ");
    }
    toFile << result << '\n';
    file.close();

    return true;
}
