#include "src/Core/mainwindow.hpp"
#include "ui_mainwindow.h"

void MainWindow::initAppearance()
{
    QFontMetrics metrics(font());
    ui->TextEdit->setTabStopWidth(4 * metrics.width('a'));
    this->setCentralWidget(ui->TextEdit);
}

void MainWindow::setCurrentFont()
{
    QFont font = QFontDialog::getFont(nullptr, centralWidget()->font());
    centralWidget()->setFont(font);
}
