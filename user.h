#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>

class User {
public:
    User();
    void setName(const QString &name);
    void setAge(const int age);
    void setBirthday(const QDate &birthday);
    QString getName() const;
    int getAge() const;
    QDate getBirthday() const;
    bool serialize(const QString &filePath);
    bool deserialize(const QString &filePath);

private:
    QString name;
    int age;
    QDate birthday;
};

#endif // USER_H
