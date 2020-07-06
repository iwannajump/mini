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
    setSettings();
}

Editor::~Editor()
{
    getSettings();
    delete themes;
    delete files;
    delete highlighter;
    delete ui;
}
