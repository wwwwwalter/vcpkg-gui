//
// Created by gzyit on 2022/5/30.
//

#ifndef VCPKG_UI_PROCESS_H
#define VCPKG_UI_PROCESS_H

#include <QObject>
#include <QProcess>
#include <QSettings>

class Process : public QProcess {
Q_OBJECT

public:
    explicit Process(QObject *parent = nullptr);
    ~Process() override;

private:
};


#endif //VCPKG_UI_PROCESS_H
