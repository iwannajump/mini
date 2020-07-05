#include "editor.hpp"

void Editor::initConnects
    (QWidget * parent)
{
    connect(ui->actionExit,             &QAction::triggered, [=]() { files->closeFile(parent); });
    connect(ui->actionSave,             &QAction::triggered, [=]() { files->saveFile(); });
    connect(ui->actionNew,              &QAction::triggered, [=]() { files->checkNewFile(); });
    connect(ui->actionOpen,             &QAction::triggered, [=]() { files->checkOpenFile(); });
    connect(ui->actionLightScheme,      &QAction::triggered, [=]() { themes->setColorSchemeLight(ui); });
    connect(ui->actionDarkScheme,       &QAction::triggered, [=]() { themes->setColorSchemeDark(ui); });
    connect(ui->actionSolarizedTheme,   &QAction::triggered, [=]() { themes->setColorSchemeSolarized(ui); });
    connect(ui->actionFont,             &QAction::triggered, [=]() { setupFont(); });
}
