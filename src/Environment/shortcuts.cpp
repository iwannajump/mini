#include "ui_mainwindow.h"
#include "src/core/mainwindow.hpp"


void MainWindow::shortcuts()
{
    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlQ, SIGNAL(activated()), this, SLOT(closeFile()));

    CtrlS = new QShortcut(this);
    CtrlS->setKey(Qt::CTRL + Qt::Key_S);
    connect(CtrlS, SIGNAL(activated()), this, SLOT(saveFile()));

    CtrlN = new QShortcut(this);
    CtrlN->setKey(Qt::CTRL + Qt::Key_N);
    connect(CtrlN, SIGNAL(activated()), this, SLOT(checkNewFile()));

    CtrlO = new QShortcut(this);
    CtrlO->setKey(Qt::CTRL + Qt::Key_O);
    connect(CtrlO, SIGNAL(activated()), this, SLOT(checkOpenFile()));
}
