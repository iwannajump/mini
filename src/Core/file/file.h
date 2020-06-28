#pragma once

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "ui_mainwindow.h"

class Files : public QWidget
{
    Q_OBJECT
public:
    Files();
    ~Files();

public slots:
    void saveFile(Ui::MainWindow * );
    void openFile(Ui::MainWindow * );
    void checkOpenFile(Ui::MainWindow * );
    void newFile(Ui::MainWindow * );
    void checkNewFile(Ui::MainWindow * );
    void closeFile(Ui::MainWindow * );

     void appearance(Ui::MainWindow *, const QString &);
};
