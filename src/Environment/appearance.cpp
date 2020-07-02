#include "src/Core/editor.hpp"
#include "ui_mainwindow.h"

void Editor::initAppearance()
{
    this->setCentralWidget(ui->TextEdit);
    QFontMetrics metrics(font());
    ui->TextEdit->setTabStopWidth(4 * metrics.width('a'));
}

void Editor::initHighlighter()
{
    highlighter = new Highlighter(ui->TextEdit->document());
    highlighter->highlightBlock(ui->TextEdit->toPlainText());
}

void Editor::setupFont()
{
    QFont font = QFontDialog::getFont(nullptr, centralWidget()->font());
    centralWidget()->setFont(font);
}

void Editor::zoomIn()
{
    ui->TextEdit->zoomIn(5);
}

void Editor::zoomOut()
{
    ui->TextEdit->zoomOut(5);
}
