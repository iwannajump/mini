#include "src/Core/mainwindow.hpp"
#include "ui_mainwindow.h"

void MainWindow::initAppearance()
{
    this->setCentralWidget(ui->TextEdit);
    QFontMetrics metrics(font());
    ui->TextEdit->setTabStopWidth(4 * metrics.width('a'));
    highlighter = new Highlighter(ui->TextEdit->document());
    highlighter->highlightBlock(ui->TextEdit->toPlainText());
}

void MainWindow::setCurrentFont()
{
    QFont font = QFontDialog::getFont(nullptr, centralWidget()->font());
    centralWidget()->setFont(font);
}
