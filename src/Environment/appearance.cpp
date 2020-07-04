#include "src/Core/editor.hpp"

void Editor::initAppearance()
{
    this->setCentralWidget(ui->textEdit);
    QFontMetrics metrics(font());
    ui->textEdit->setTabStopWidth(4 * metrics.width('a'));
}

void Editor::initHighlighter()
{
    highlighter = new Highlighter(ui->textEdit->document());
    highlighter->cppHighlight();
}

void Editor::setupFont()
{
    QFont font = QFontDialog::getFont(nullptr, centralWidget()->font());
    centralWidget()->setFont(font);
}

void Editor::zoomIn() { ui->textEdit->zoomIn(5); }

void Editor::zoomOut() { ui->textEdit->zoomOut(5); }
