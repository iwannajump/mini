#include "src/Core/editor.hpp"
#include "ui_editor.h"

void Editor::initConnects
    (QWidget * parent)
{
    connect(ui->actionExit,             &QAction::triggered, [=]() { files->closeFile(parent); });
    connect(ui->actionSave,             &QAction::triggered, [=]() { files->saveFile(); });
    connect(ui->actionNew,              &QAction::triggered, [=]() { files->checkNewFile(); });
    connect(ui->actionOpen,             &QAction::triggered, [=]() { files->checkOpenFile(); });
    connect(ui->actionLightScheme,      &QAction::triggered, [=]() { themes->setColorSchemeLight(); });
    connect(ui->actionDarkScheme,       &QAction::triggered, [=]() { themes->setColorSchemeDark(); });
    connect(ui->actionSolarizedTheme,   &QAction::triggered, [=]() { themes->setColorSchemeSolarized(); });
    connect(ui->actionFont,             &QAction::triggered, [=]() { this->setupFont(); });
    connect(ui->actionHelp,             &QAction::triggered, [=]() { help->showHelpWindow(); });
}
