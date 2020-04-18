#include "../mainwindow.hpp"
#include "../ui_mainwindow.h"


void MainWindow::saveFile()
{

    ui->actionSave->setToolTip("Saving file");
    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save file"), "",
                                                        tr("Text file (*.txt);;"
                                                           "Bash script (*.sh);;"
                                                           "Makefile;;"
                                                           "C++ Source file (*.cpp);;"
                                                           "C++ Header file (*.h);;"
                                                           "Object file (*.o);;"
                                                           "All files(*)"));

        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
            //return;
        }
        else
        {
            QTextStream out(&file);
            QString text = ui->TextEdit->toPlainText();
            out << text;
            appearance(fileName);
            file.close();
        }
    }
}

void MainWindow::openFile()
{

    ui->actionOpen->setToolTip("Open file");
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open file"), "",
                                                    tr("Text file (*.txt);;"
                                                       "Bash script (*.sh);;"
                                                       "Makefile;;"
                                                       "C++ Source file (*.cpp);;"
                                                       "C++ Header file (*.h);;"
                                                       "Object file (*.o);;"
                                                       "All files(*)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
    }
    else
    {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->TextEdit->setPlainText(text);

        appearance(fileName);
        file.close();
    }

}

void MainWindow::checkOpenFile()
{

    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {
        QMessageBox ask;
        auto a = QMessageBox::question(this, "Warning", "Do you want to save an existing file?",
                                       QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile();
        }
        openFile();

    }
    else openFile();
}


void MainWindow::newFile()
{

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("New file"), "",
                                                    tr("Text file (*.txt);;"
                                                       "Bash script (*.sh);;"
                                                       "Makefile (Makefile);;"
                                                       "C++ Source file (*.cpp);;"
                                                       "C++ Header file (*.h);;"
                                                       "Object file (*.o);;"
                                                       "All files(*)"));

    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    else
    {
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->TextEdit->toPlainText();
        out << text;
        appearance(fileName);
        file.close();
    }

}


void MainWindow::checkNewFile()
{

    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {

        auto a = QMessageBox::question(this, "Warning", "Do you want to save an existing file?",
                                       QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile();
        }
        newFile();

    }
    else newFile();
}


void MainWindow::closeFile()
{

    if (!(ui->TextEdit->toPlainText().isEmpty()))
    {

//        QMessageBox ask;
        auto a = QMessageBox::question(this, "Warning", "Do you want to save an existing file?",
                                       QMessageBox::Yes | QMessageBox::No);

        if (a == QMessageBox::Yes)
        {
            saveFile();
        }
        close();

    }
    else close();
}











