#include "src/Core/mainwindow.hpp"
#include "ui_mainwindow.h"

void MainWindow::initAppearance()
{
    this->setCentralWidget(ui->TextEdit);
    QFontMetrics metrics(font());
    ui->TextEdit->setTabStopWidth(4 * metrics.width('a'));
}

void MainWindow::initHighlighter()
{
    highlighter = new Highlighter(ui->TextEdit->document());
    highlighter->highlightBlock(ui->TextEdit->toPlainText());
}

void MainWindow::setupFont()
{
    QFont font = QFontDialog::getFont(nullptr, centralWidget()->font());
    centralWidget()->setFont(font);
}

void MainWindow::zoomIn()
{
    ui->TextEdit->zoomIn(5);
}

void MainWindow::zoomOut()
{
    ui->TextEdit->zoomOut(5);
}
