#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::shortcuts()
{
    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlQ, SIGNAL(activated()), this, SLOT(close()));

    CtrlS = new QShortcut(this);
    CtrlS->setKey(Qt::CTRL + Qt::Key_S);
    connect(CtrlS, SIGNAL(activated()), this, SLOT(saveFileAs()));

    CtrlN = new QShortcut(this);
    CtrlN->setKey(Qt::CTRL + Qt::Key_N);
    connect(CtrlN, SIGNAL(activated()), this, SLOT(newFile()));

    CtrlO = new QShortcut(this);
    CtrlO->setKey(Qt::CTRL + Qt::Key_O);
    connect(CtrlO, SIGNAL(activated()), this, SLOT(openFile()));

}
