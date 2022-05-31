//
// Created by gzyit on 2022/5/30.
//

#ifndef VCPKG_DIALOG_H
#define VCPKG_DIALOG_H

#include <QDialog>
#include "process.h"
#include <QSettings>
#include <QListWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog {
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    int setInformation(const QString& information);
    int do_read();
    int doInstallDry();
    int doInstall();
    int doRemove();
    int do_process(QProcess *process,QString vcpkg_root,QString exec,QStringList args);



    ~Dialog() override;

private:
    Ui::Dialog *ui{};
    QString information;
    QString packageName;
    Process *process;
    QSettings *settings;
    QString vcpkg_root;
};


#endif //VCPKG_DIALOG_H
