//
// Created by gzyit on 2022/5/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Process.h" resolved

#include "process.h"
#include <QDebug>


Process::~Process() = default;

Process::Process(QObject *parent) : QProcess(parent) {
    this->setProcessChannelMode(QProcess::MergedChannels);
}


