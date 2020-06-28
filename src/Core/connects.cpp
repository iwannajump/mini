#include "mainwindow.hpp"

void MainWindow::initConnects()
{
    connect(ui->actionExit, &QAction::triggered, [=]() { files->closeFile(ui); });
    connect(ui->actionSave, &QAction::triggered, [=]() { files->saveFile(ui); });
    connect(ui->actionNew,  &QAction::triggered, [=]() { files->checkNewFile(ui); });
    connect(ui->actionOpen, &QAction::triggered, [=]() { files->checkOpenFile(ui); });
    connect(ui->actionlight,    SIGNAL(triggered()), SLOT(setColorSchemeLight()));
    connect(ui->actiondark,     SIGNAL(triggered()), SLOT(setColorSchemeDark()));
    connect(ui->actionsolarized,SIGNAL(triggered()), SLOT(setColorSchemeSolarized()));
    connect(ui->QAChangeFont,   SIGNAL(triggered()), SLOT(setCurrentFont()));
}
