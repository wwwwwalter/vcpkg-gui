//
// Created by gzyit on 2022/5/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dialog.h"
#include <QRegExp>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QFile>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowIcon(QIcon(":/Images/Microsoft.ico"));
    process = new Process(this);
    connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::do_print);
    process_cmd = new Process(this);
    connect(process_cmd, &QProcess::readyReadStandardOutput, this, &MainWindow::do_cmd_print);
    connect(process_cmd, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,
            &MainWindow::do_cmd_finished);

    process_clone = new Process(this);
    connect(process_clone, &QProcess::readyReadStandardOutput, this, &MainWindow::do_clone_print);
    connect(process_clone, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,
            &MainWindow::do_clone_finished);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::do_search);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::do_install);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::do_list);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::do_git_pull);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::do_update);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::do_upgrade);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::do_clean);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::do_clear);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::do_choose_vcpkg_path);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::do_bootstrap);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::do_integrate);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::do_clone);


    ui->listWidget->setAlternatingRowColors(true);
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::do_item_details);
    //connect(ui->listWidget, &QListWidget::itemDoubleClicked, ui->listWidget, &QListWidget::openPersistentEditor);

    ui->lineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::do_search);

    ui->lineEdit_2->setAttribute(Qt::WA_InputMethodEnabled, false);
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, this, &MainWindow::do_cmd);

    settings = new QSettings("vcpkg.ini", QSettings::IniFormat, this);
    this->vcpkg_root = settings->value("vcpkg/vcpkg_root").toString();
    this->vcpkg_root_ready = settings->value("vcpkg/vcpkg_root_ready").toString();

    if (vcpkg_root.isEmpty() || vcpkg_root_ready != "true")
        setPushbuttonDisable();
}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::do_search() {
    ui->listWidget->clear();
    QString exec = "vcpkg";
    QStringList args;
    args << "search" << "--x-full-desc" << ui->lineEdit->text();
    do_process(process, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_print() {
    QByteArray array;
    while ((array = process->readLine(1024)) != nullptr) {
        array.chop(1);
        QString record = array;
        QStringList list = record.split(QRegExp("\\s\\s+"));
        record = list.join("\t");
        ui->listWidget->addItem(record);
    }
    ui->label->setText("port:" + QString::number(ui->listWidget->count()));
    return 0;
}

int MainWindow::do_item_details(QListWidgetItem *item) {
    QString information = item->text();
    Dialog dialog(this);
    dialog.setInformation(information);
    dialog.exec();
    return 0;
}

int MainWindow::do_list() {
    ui->listWidget->clear();
    QString exec = "vcpkg";
    QStringList args;
    args << "list" << "--x-full-desc";
    do_process(process, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_git_pull() {
    QString exec = "git";
    QStringList args;
    args << "pull";
    do_process(process_cmd, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_update() {
    QString exec = "vcpkg";
    QStringList args;
    args << "update";
    do_process(process_cmd, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_clean() {
    QString exec = "vcpkg";
    QStringList args;
    args << "remove" << "--outdated";
    do_process(process_cmd, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_install() {
    if (ui->listWidget->currentItem() == nullptr) return -1;
    QString record = ui->listWidget->currentItem()->text();
    QString packageName = record.split('\t').first();
    QString exec = "vcpkg";
    QStringList args;
    if (packageName.contains("x64-windows")) {
        args << "install" << packageName;
    } else {
        args << "install" << packageName + ":x64-windows";
    }
    do_process(process_cmd, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_upgrade() {
    QString exec = "vcpkg";
    QStringList args;
    args << "upgrade";
    do_process(process_cmd, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_cmd_print() {
    QByteArray array;
    while ((array = process_cmd->readLine(1024)) != nullptr) {
        array.chop(1);
        ui->textEdit_2->append(array);
        ui->textEdit_2->moveCursor(QTextCursor::End);
    }
    return 0;
}

int MainWindow::do_clone_print() {
    QByteArray array;
    while ((array = process_clone->readLine(1024)) != nullptr) {
        array.chop(1);
        ui->textEdit_2->append(array);
        ui->textEdit_2->moveCursor(QTextCursor::End);
    }
    return 0;
}

int MainWindow::do_clone_finished(int exitCode, QProcess::ExitStatus exitStatus) {
    ui->textEdit_2->append("exitCode:" + QString::number(exitCode));
    ui->textEdit_2->append("==============cmd done==============");
    if (exitCode == 0) {
        vcpkg_root_ready = "true";
        settings->setValue("vcpkg/vcpkg_root_ready", vcpkg_root_ready);
        setPushButtonEnable();
    } else {
        QDir dir(vcpkg_root+"/.git");
        if(dir.exists()){
            ui->pushButton_10->setEnabled(true);//bootstrap
        }
        return exitCode;
    }
    return 0;
}


int MainWindow::do_cmd_finished(int exitCode, QProcess::ExitStatus exitStatus) {
    ui->textEdit_2->append("exitCode:" + QString::number(exitCode));
    ui->textEdit_2->append("==============cmd done==============");
    return 0;
}

int MainWindow::do_cmd() {
    QStringList cmd = ui->lineEdit_2->text().split(" ");
    QString exec = cmd.first();
    cmd.pop_front();
    QStringList args = cmd;
    do_process(process_cmd, vcpkg_root, exec, args);
    ui->lineEdit_2->clear();
    return 0;
}

int MainWindow::do_clear() {
    ui->textEdit_2->clear();
    return 0;
}

int MainWindow::do_choose_vcpkg_path() {
    QDialog qDialog;
    qDialog.setMinimumSize(400, 80);
    auto *layout = new QHBoxLayout(&qDialog);
    auto *edit = new QLineEdit(&qDialog);
    edit->setAttribute(Qt::WA_InputMethodEnabled, false);
    QString vcpkg_root_old = vcpkg_root;
    edit->setText(vcpkg_root_old);
    auto *button = new QPushButton(&qDialog);
    button->setText("OK");
    layout->addWidget(new QLabel("vcpkg root:"));
    layout->addWidget(edit);
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, &qDialog, &QDialog::accept);
    connect(button, &QPushButton::clicked, this, [&] {
        vcpkg_root = edit->text();
        settings->setValue("vcpkg/vcpkg_root", vcpkg_root);
        QDir dir(vcpkg_root);
        if (!dir.exists())
            dir.mkpath(vcpkg_root);
    });

    if (qDialog.exec()) {
        if (vcpkg_root_old != vcpkg_root) {
#ifdef _WIN32
            QFile file(vcpkg_root+"/vcpkg.exe");
#elif
            QFile file(vcpkg_root+"vcpkg");
#endif
            qDebug()<<file.exists();
            if(!file.exists()){
                setPushbuttonDisable();
                vcpkg_root_ready = "false";
                settings->setValue("vcpkg/vcpkg_root", vcpkg_root);
            }else{
                setPushButtonEnable();
                vcpkg_root_ready = "true";
                settings->setValue("vcpkg/vcpkg_root", vcpkg_root);
            }


        }
        if (!vcpkg_root.isEmpty())
        {
            QDir dir(vcpkg_root+"/.git");
            if(dir.exists()){
                ui->pushButton_10->setEnabled(true);
            }
            ui->pushButton_12->setEnabled(true);
        }
    }
    return 0;
}

int MainWindow::do_clone() {
    QString exec = "git";
    QStringList args;
    args << "clone" << "git@github.com:microsoft/vcpkg.git" << ".";
    do_process(process_clone, vcpkg_root, exec, args);
    return 0;
}

int MainWindow::do_bootstrap() {
    //bootstrap-vcpkg.sh
    QString exec = "bootstrap-vcpkg.bat";
    QStringList args;
    do_process(process_cmd, vcpkg_root, exec, args);
    setPushButtonEnable();
    return 0;
}

int MainWindow::do_integrate() {
    //vcpkg integrate install
    QString exec = "vcpkg";
    QStringList args;
    args << "integrate" << "install";
    do_process(process_cmd, vcpkg_root, exec, args);
    return 0;
}


int MainWindow::do_process(QProcess *process, QString work_dir, QString exec, QStringList args) {
    ui->textEdit_2->append(work_dir + "$" + exec + " " + args.join(' '));
    QString cmd_begin(100, '*');
    ui->textEdit_2->append(cmd_begin);

    process->setWorkingDirectory(work_dir);
    process->start(exec, args);
    return 0;
}

int MainWindow::setPushbuttonDisable() {
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);
    ui->pushButton_12->setDisabled(true);
    return 0;
}

int MainWindow::setPushButtonEnable() {
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    return 0;
}







