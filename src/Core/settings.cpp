#include "editor.hpp"

void Editor::saveSettings()
{
    QSettings settings("mini", "mini");
    this->centralWidget()->setFont
            (settings.value("font", QFont()).value<QFont>());
    ui->textEdit->setStyleSheet
            (settings.value("stylesheet/editor", QString()).value<QString>());
    ui->menuBar->setStyleSheet
            (settings.value("stylesheet/menubar", QString()).value<QString>());
    ui->statusBar->setStyleSheet
            (settings.value("stylesheet/statusbar", QString()).value<QString>());
    ui->textEdit->setPlainText
            (settings.value("file", QString()).value<QString>());
}

void Editor::loadSettings()
{
    QSettings settings("mini", "mini");
    settings.setValue
            ("font", this->centralWidget()->font());
    settings.setValue
            ("stylesheet/editor", ui->textEdit->styleSheet());
    settings.setValue
            ("stylesheet/menubar", ui->menuBar->styleSheet());
    settings.setValue
            ("stylesheet/statusbar", ui->statusBar->styleSheet());
    settings.setValue
            ("file", ui->textEdit->toPlainText());
}
