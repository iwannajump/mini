#include "file.hpp"
#include "ui_mainwindow.h"

void Files::saveFile(Ui::MainWindow * ui)
{
    ui->actionSave->setToolTip("Saving file");

    if (!ui->TextEdit->toPlainText().isEmpty())
    {
        QString fileName =
        QFileDialog::getSaveFileName
        (
        this, tr("Save file"), "",
        tr("Text file (*.txt);;"
           "Bash script (*.sh);;"
           "Makefile;;"
           "C++ Source file (*.c *.cpp);;"
           "C++ Header file (*.h *.hpp);;"
           "Object file (*.o);;"
           "All files(*)")
        );

        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning
                    (this, "Warning",
                     "Cannot save file : " + file.errorString());
        }
        QTextStream out(&file);
        QString text = ui->TextEdit->toPlainText();
        out << text;
        file.close();
    }
}


void Files::openFile(Ui::MainWindow * ui)
{
    ui->actionOpen->setToolTip("Open file");

    QString fileName =
    QFileDialog::getOpenFileName
    (
    this, tr("Save file"), "",
    tr("Text file (*.txt);;"
       "Bash script (*.sh);;"
       "Makefile;;"
       "C++ Source file (*.c *.cpp);;"
       "C++ Header file (*.h *.hpp);;"
       "Object file (*.o);;"
       "All files(*)")
    );

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning
                (this, "Warning",
                 "Cannot open file : " + file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->TextEdit->setPlainText(text);
    appearance(ui, fileName);
    file.close();
}


void Files::checkOpenFile(Ui::MainWindow * ui)
{
    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {
        QMessageBox ask;
        auto a = QMessageBox::question
                (this, "Warning", "Do you want to save an existing file?",
                 QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile(ui);
        }
        openFile(ui);
    }
    else openFile(ui);
}


void Files::newFile(Ui::MainWindow * ui)
{
    QString fileName =
    QFileDialog::getSaveFileName
    (
    this, tr("Save file"), "",
    tr("Text file (*.txt);;"
       "Bash script (*.sh);;"
       "Makefile;;"
       "C++ Source file (*.c *.cpp);;"
       "C++ Header file (*.h *.hpp);;"
       "Object file (*.o);;"
       "All files(*)")
    );

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning
                (this, "Warning",
                 "Cannot save file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->TextEdit->toPlainText();
    out << text;
    appearance(ui, fileName);
    file.close();
}


void Files::checkNewFile(Ui::MainWindow * ui)
{
    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {
        auto a = QMessageBox::question
                (this, "Warning", "Do you want to save an existing file?",
                 QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile(ui);
        }
        newFile(ui);
    }
    else newFile(ui);
}


void Files::closeFile(Ui::MainWindow * ui)
{
    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {
        auto a = QMessageBox::question
                (this, "Warning", "Do you want to save an existing file?",
                 QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile(ui);
        }
        close();
    }
    else close();
}

void Files::appearance(Ui::MainWindow * ui, const QString &fileName)
{
    setWindowTitle(fileName);
    ui->statusBar->showMessage(fileName);
}

