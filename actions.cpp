#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::saveFileAs() {

    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->TextEdit->toPlainText();
    out << text;
    file.close();


}

void MainWindow::openFile() {

    ui->actionOpen->setToolTip("Open file");
    QString fileName = QFileDialog::getOpenFileName(this,
                       tr("Open file"), "",
                       tr("File (*.txt);;All files(*)"));
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());


    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->TextEdit->setText(text);
    file.close();

}


void MainWindow::newFile() {

    QString fileName = QFileDialog::getSaveFileName(this,
                       tr("Create a new file"), "",
                       tr("File (*.txt);;All files(*)"));

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    else {
        currentFile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->TextEdit->toPlainText();
        out << text;
        file.close();
    }
}
