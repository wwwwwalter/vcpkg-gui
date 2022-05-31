//
// Created by gzyit on 2022/5/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Dialog.h" resolved

#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QWidget>



Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
    ui->listWidget->setAlternatingRowColors(true);
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, ui->listWidget, &QListWidget::openPersistentEditor);

    connect(ui->pushButton, &QPushButton::clicked, this, &Dialog::doInstall);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Dialog::doRemove);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Dialog::doInstallDry);

    process = new Process(this);
    connect(process, &QProcess::readyReadStandardOutput, this, &Dialog::do_read);

    settings = new QSettings("vcpkg.ini", QSettings::IniFormat, this);
    vcpkg_root = settings->value("vcpkg/vcpkg_root").toString();

}

Dialog::~Dialog() {
    delete ui;
}

int Dialog::setInformation(const QString &information) {
    this->information = information;
    QStringList info_list = information.split('\t');
    this->packageName = information.split('\t').first();
    this->setWindowTitle(packageName);
    for (auto item: info_list)
        ui->listWidget->addItem(item);


    return 0;
}

int Dialog::doInstallDry() {
    QString exec = "vcpkg";
    QStringList args;
    if (packageName.contains("x64-windows")) {
        args << "install" << "--dry-run" << packageName;
    } else {
        args << "install" << "--dry-run" << packageName + ":x64-windows";
    }
    do_process(process, vcpkg_root, exec, args);
    return 0;
}

int Dialog::doInstall() {

    QString exec = "vcpkg";
    QStringList args;
    if (packageName.contains("x64-windows")) {
        args << "install" << packageName;
    } else {
        args << "install" << packageName + ":x64-windows";
    }
    do_process(process, vcpkg_root, exec, args);
    return 0;
}

int Dialog::doRemove() {
    QString exec = "vcpkg";
    QStringList args;
    qDebug() << packageName;
    if (packageName.contains("x64-windows")) {
        args << "remove" << packageName;
    } else {
        args << "remove" << packageName + ":x64-windows";
    }
    do_process(process, vcpkg_root, exec, args);
    return 0;
}

int Dialog::do_read() {
    ui->listWidget->clear();
    QByteArray array;
    while ((array = process->readLine(1024)) != nullptr) {
        array.chop(1);
        ui->listWidget->addItem(array);
    }
    return 0;
}


int Dialog::do_process(QProcess *process, QString vcpkg_root, QString exec, QStringList args) {
    process->setWorkingDirectory(vcpkg_root);
    process->start(exec, args);
    return 0;
}

