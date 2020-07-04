#include "src/Core/editor.hpp"


void Editor::initShortcuts
    (QWidget * parent)
{
    QShortcut * CtrlQ{}; //exit
    QShortcut * CtrlS{}; //save
    QShortcut * CtrlN{}; //new file
    QShortcut * CtrlO{}; //open
    QShortcut * ZoomOut{};
    QShortcut * ZoomIn{};

    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlQ, &QShortcut::activated,   [=]() { files->closeFile(ui, parent); });

    CtrlS = new QShortcut(this);
    CtrlS->setKey(Qt::CTRL + Qt::Key_S);
    connect(CtrlS, &QShortcut::activated,   [=]() { files->saveFile(ui); });

    CtrlN = new QShortcut(this);
    CtrlN->setKey(Qt::CTRL + Qt::Key_N);
    connect(CtrlN, &QShortcut::activated,   [=]() { files->checkNewFile(ui); });

    CtrlO = new QShortcut(this);
    CtrlO->setKey(Qt::CTRL + Qt::Key_O);
    connect(CtrlO, &QShortcut::activated,   [=]() { files->checkOpenFile(ui); });

    ZoomOut = new QShortcut(this);
    ZoomOut->setKey(Qt::CTRL + Qt::Key_Minus);
    connect(ZoomOut,  &QShortcut::activated,    [=]() { this->zoomOut(); });

    ZoomIn = new QShortcut(this);
    ZoomIn->setKey(Qt::CTRL + Qt::Key_Equal);
    connect(ZoomIn,  &QShortcut::activated,     [=]() { this->zoomIn(); });
}
