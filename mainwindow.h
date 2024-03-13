#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>
#include <QPushButton>
#include "user.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onSerializeClicked();
    void onDeserializeClicked();

private:
    QLineEdit *nameLineEdit;
    QSpinBox *ageSpinBox;
    QDateEdit *birthdayDateEdit;
    QPushButton *serializeButton;
    QPushButton *deserializeButton;
    User user;
};

#endif // MAINWINDOW_H
