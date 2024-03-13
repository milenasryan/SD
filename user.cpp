#include "user.h"
#include <QFile>
#include <QTextStream>
#include "QDebug"

User::User() : age(0) {}

void User::setName(const QString &name) {
    this->name = name;
}

void User::setAge(const int age) {
    this->age = age;
}

void User::setBirthday(const QDate &birthday) {
    this->birthday = birthday;
}

QString User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

QDate User::getBirthday() const {
    return birthday;
}

bool User::serialize(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << name << "\n";
    out << age << "\n";
    out << birthday.toString(Qt::ISODate) << "\n";

    file.close();

    qDebug() << "Data serialized to file:" << filePath;
    return true;
}

bool User::deserialize(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    name = in.readLine();
    age = in.readLine().toInt();
    birthday = QDate::fromString(in.readLine(), Qt::ISODate);

    file.close();
    return true;
}
