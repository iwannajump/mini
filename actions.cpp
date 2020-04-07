#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::saveFile() {

    if (!(ui->TextEdit->toPlainText().isEmpty())) {
        QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Open file"), "",
                            tr("Text file (*.txt);;"
                            "Bash script (*.sh);;"
                            "Makefile;;"
                            "C++ Source file (*.cpp);;"
                            "C++ Header file (*.h);;"
                            "Object file (*.o);;"
                            "All files(*)"));

        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))
                QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());

        currentFile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->TextEdit->toPlainText();
        out << text;
        file.close();
    }
}

void MainWindow::openFile() {

    ui->actionOpen->setToolTip("Open file");
    QString fileName =  QFileDialog::getOpenFileName(this,
                        tr("Open file"), "",
                        tr("Text file (*.txt);;"
                        "Bash script (*.sh);;"
                        "Makefile;;"
                        "C++ Source file (*.cpp);;"
                        "C++ Header file (*.h);;"
                        "Object file (*.o);;"
                        "All files(*)"));
    QFile file(fileName);
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());


    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->TextEdit->setText(text);
    file.close();

    ui->statusBar->showMessage(fileName);


}


void MainWindow::newFile() {

    QString fileName =  QFileDialog::getSaveFileName(this,
                        tr("Open file"), "",
                        tr("Text file (*.txt);;"
                        "Bash script (*.sh);;"
                        "Makefile (Makefile);;"
                        "C++ Source file (*.cpp);;"
                        "C++ Header file (*.h);;"
                        "Object file (*.o);;"
                        "All files(*)"));

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

    ui->statusBar->showMessage(fileName);
}
