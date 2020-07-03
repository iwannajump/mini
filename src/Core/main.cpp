#include "editor.hpp"
#include <QApplication>

int main
    (int argc, char *argv[])
{
    QApplication a(argc, argv);
    Editor editor;
    editor.resize(800, 600);
    editor.show();
    return QApplication::exec();
}
