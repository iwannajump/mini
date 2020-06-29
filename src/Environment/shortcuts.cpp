#include "ui_mainwindow.h"
#include "src/Core/mainwindow.hpp"


void MainWindow::initShortcuts()
{
    QShortcut * CtrlQ{}; //exit
    QShortcut * CtrlS{}; //save
    QShortcut * CtrlN{}; //new file
    QShortcut * CtrlO{}; //open

    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlQ, &QShortcut::activated, [=]() { files->closeFile(ui); });

    CtrlS = new QShortcut(this);
    CtrlS->setKey(Qt::CTRL + Qt::Key_S);
    connect(CtrlS, &QShortcut::activated, [=]() { files->saveFile(ui); });

    CtrlN = new QShortcut(this);
    CtrlN->setKey(Qt::CTRL + Qt::Key_N);
    connect(CtrlN, &QShortcut::activated, [=]() { files->checkNewFile(ui); });

    CtrlO = new QShortcut(this);
    CtrlO->setKey(Qt::CTRL + Qt::Key_O);
    connect(CtrlO, &QShortcut::activated, [=]() { files->checkOpenFile(ui); });
}
