#include <QApplication>
#include "mainwindow.h"
#include <QFont>


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow m;
    QFont font = QApplication::font();
    font.setPointSize(10);
    font.setFamily("Microsoft YaHei");
    QApplication::setFont(font);

    m.setWindowTitle("vcpkg-gui");
    m.show();

    return QApplication::exec();
}
