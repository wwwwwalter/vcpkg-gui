//
// Created by gzyit on 2022/5/30.
//

#ifndef UNTITLED5_MAINWINDOW_H
#define UNTITLED5_MAINWINDOW_H

#include <QWidget>
#include <QProcess>
#include <QListWidget>
#include <QListWidgetItem>
#include "process.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    int do_search();

    int do_item_details(QListWidgetItem *item);

    int do_install();

    int do_list();

    int do_print();

    int do_cmd();

    int do_cmd_print();

    int do_clone_print();

    int do_clone_finished(int exitCode, QProcess::ExitStatus exitStatus);

    int do_cmd_finished(int exitCode, QProcess::ExitStatus exitStatus);

    int do_git_pull();

    int do_update();

    int do_upgrade();

    int do_clean();

    int do_clear();

    int do_choose_vcpkg_path();

    int do_bootstrap();

    int do_integrate();

    int do_clone();

    int do_process(QProcess *process, QString work_dir, QString exec, QStringList args);

    int setPushButtonEnable();

    int setPushbuttonDisable();

    int do_state(QProcess::ProcessState state);


private:
    Ui::MainWindow *ui;
    Process *process;
    Process *process_cmd;
    Process *process_clone;
    QString vcpkg_root;
    QString vcpkg_root_ready;
    QSettings *settings;


};


#endif //UNTITLED5_MAINWINDOW_H
