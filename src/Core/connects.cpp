#include "mainwindow.hpp"

void MainWindow::initConnects()
{
    connect(ui->actionExit,             &QAction::triggered, [=]() { files->closeFile(ui); });
    connect(ui->actionSave,             &QAction::triggered, [=]() { files->saveFile(ui); });
    connect(ui->actionNew,              &QAction::triggered, [=]() { files->checkNewFile(ui); });
    connect(ui->actionOpen,             &QAction::triggered, [=]() { files->checkOpenFile(ui); });
    connect(ui->actionLightScheme,      &QAction::triggered, [=]() { themes->setColorSchemeLight(ui); });
    connect(ui->actionDarkScheme,       &QAction::triggered, [=]() { themes->setColorSchemeDark(ui); });
    connect(ui->actionSolarizedTheme,   &QAction::triggered, [=]() { themes->setColorSchemeSolarized(ui); });
    connect(ui->actionFont,             &QAction::triggered, [=]() { setupFont(); });
}
