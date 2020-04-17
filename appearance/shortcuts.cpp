#include "../mainwindow.hpp"
#include "../ui_mainwindow.h"


void MainWindow::shortcuts() {

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


    //    scrollUp = new QShortcut(this);
    //    scrollUp->setKey(Qt::CTRL + Qt::Key_0);
    //    connect(scrollUp, SIGNAL(activated()), this, SLOT(zoomIn()));

    //    scrollDown = new QShortcut(this);
    //    scrollDown->setKey(Qt::CTRL + Qt::Key_Minus);
    //    connect(scrollDown, SIGNAL(activated()), this, SLOT(zoomOut()));
}
