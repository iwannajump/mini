#include "file.hpp"
#include <QDebug>

Files::Files(Ui::Editor * window_ui)
{
    ui = window_ui;
}

void Files::saveFile()
{
    ui->actionSave->setToolTip("Saving file");

    if (!ui->textEdit->toPlainText().isEmpty())
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
//        QFileInfo extension(file);
//        return extension.suffix();
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning
                    (this, "Warning",
                     "Cannot save file : " + file.errorString());
            return;
        }
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
    }
}

void Files::openFile()
{
    ui->actionOpen->setToolTip("Open file");

    QString fileName =
    QFileDialog::getOpenFileName
    (
    this, tr("Open file"), "",
    tr("Text file (*.txt);;"
       "Bash script (*.sh);;"
       "Makefile;;"
       "C++ Source file (*.c *.cpp);;"
       "C++ Header file (*.h *.hpp);;"
       "Object file (*.o);;"
       "All files(*)")
    );

    QFile file(fileName);
//    QFileInfo extension(file);
//    return extension.suffix();
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning
                (this, "Warning",
                 "Cannot open file : " + file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);
    appearance(fileName);
    file.close();
}

void Files::checkOpenFile()
{
    if (!(ui->textEdit->toPlainText().isEmpty()))
    {
        QMessageBox ask;
        auto a = QMessageBox::question
                (this, "Warning", "Do you want to save an existing file?",
                 QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile();
        }
        openFile();
    }
    else openFile();
}

void Files::newFile()
{
    QString fileName =
    QFileDialog::getSaveFileName
    (
    this, tr("New file"), "",
    tr("Text file (*.txt);;"
       "Bash script (*.sh);;"
       "Makefile;;"
       "C++ Source file (*.c *.cpp);;"
       "C++ Header file (*.h *.hpp);;"
       "Object file (*.o);;"
       "All files(*)")
    );

    QFile file(fileName);
//    QFileInfo extension(file);
//    return extension.suffix();
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning
                (this, "Warning",
                 "Cannot save file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    appearance(fileName);
    file.close();
}

void Files::checkNewFile()
{
    if (!(ui->textEdit->toPlainText().isEmpty()))
    {
        auto a = QMessageBox::question
                (this, "Warning", "Do you want to save an existing file?",
                 QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile();
        }
        newFile();
    }
    else newFile();
}

void Files::closeFile(QWidget * parent)
{
    if (!(ui->textEdit->toPlainText().isEmpty()))
    {
        auto a = QMessageBox::question
                (this, "Warning", "Do you want to save an existing file?",
                 QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile();
        }
        parent->close();
    }
    else parent->close();
}

void Files::appearance(const QString &fileName)
{
    setWindowTitle(fileName);
    ui->statusBar->showMessage(fileName, /*timeout = */0/*infinity*/);
}
