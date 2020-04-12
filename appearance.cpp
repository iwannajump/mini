#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::appearance(QString fileName) {

    setWindowTitle(fileName);
    ui->statusBar->showMessage(fileName);

}


void MainWindow::setCurrentFont() {

    centralWidget()->setFont(QFontDialog::getFont(0, centralWidget()->font()));

}
