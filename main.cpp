#include "mainwindow.hpp"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800, 600);
    w.show();
    return QApplication::exec();
}
