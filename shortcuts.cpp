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

}
