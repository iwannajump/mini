#include "src/Core/editor.hpp"

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Editor)
{
    ui->setupUi(this);
    initAppearance();
    initConnects(parent);
    initShortcuts(parent);
    initHighlighter();
    saveSettings();
}

Editor::~Editor()
{
    loadSettings();
    delete themes;
    delete files;
    delete highlighter;
    delete ui;
}
