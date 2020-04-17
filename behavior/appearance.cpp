#include "../mainwindow.hpp"
#include "../ui_mainwindow.h"
#include <QDebug>

void MainWindow::appearance(const QString &fileName) {

    setWindowTitle(fileName);
    ui->statusBar->showMessage(fileName);

}


void MainWindow::setCurrentFont() {
    QFont font = QFontDialog::getFont(nullptr, centralWidget()->font());
    centralWidget()->setFont(font);
    this->config.font_name = font.family();
    this->config.font_size = font.pointSize();
    this->cfg->saveConfig(this->config);
}


