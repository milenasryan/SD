#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QVBoxLayout *inputLayout = new QVBoxLayout();
    QVBoxLayout *buttonsLayout = new QVBoxLayout();

    nameLineEdit = new QLineEdit(centralWidget);
    ageSpinBox = new QSpinBox(centralWidget);
    birthdayDateEdit = new QDateEdit(centralWidget);
    serializeButton = new QPushButton("Serialize", centralWidget);
    deserializeButton = new QPushButton("Deserialize", centralWidget);

    ageSpinBox->setRange(0, 150);
    birthdayDateEdit->setCalendarPopup(true);

    inputLayout->addWidget(new QLabel("Name:", centralWidget));
    inputLayout->addWidget(nameLineEdit);
    inputLayout->addWidget(new QLabel("Age:", centralWidget));
    inputLayout->addWidget(ageSpinBox);
    inputLayout->addWidget(new QLabel("Birthday:", centralWidget));
    inputLayout->addWidget(birthdayDateEdit);

    buttonsLayout->addSpacing(40);

    buttonsLayout->addWidget(serializeButton);
    buttonsLayout->addWidget(deserializeButton);
    buttonsLayout->addStretch();

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonsLayout);

    setCentralWidget(centralWidget);

    connect(serializeButton, &QPushButton::clicked, this, &MainWindow::onSerializeClicked);
    connect(deserializeButton, &QPushButton::clicked, this, &MainWindow::onDeserializeClicked);
}

void MainWindow::onSerializeClicked() {
    user.setName(nameLineEdit->text());
    user.setAge(ageSpinBox->value());
    user.setBirthday(birthdayDateEdit->date());

    if(user.serialize("/home/milena/SD/data.txt")) {
        QMessageBox::information(this, "Success", "Data successfully serialized to file.");
    } else {
        QMessageBox::critical(this, "Error", "Could not serialize data to file.");
    }
}

void MainWindow::onDeserializeClicked() {
    if(user.deserialize("/home/milena/SD/data.txt")) {
        nameLineEdit->setText(user.getName());
        ageSpinBox->setValue(user.getAge());
        birthdayDateEdit->setDate(user.getBirthday());
        QMessageBox::information(this, "Success", "Data successfully deserialized from file.");
    } else {
        QMessageBox::critical(this, "Error", "Could not deserialize data from file.");
    }
}
