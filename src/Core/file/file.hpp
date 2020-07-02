#pragma once

#include <ui_mainwindow.h>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

class Files : public QWidget
{
    Q_OBJECT

public slots:
    void saveFile(Ui::Editor * );
    void openFile(Ui::Editor * );
    void checkOpenFile(Ui::Editor * );
    void newFile(Ui::Editor * );
    void checkNewFile(Ui::Editor * );
    void closeFile(Ui::Editor *, QWidget * );
    void appearance(Ui::Editor *, const QString & );
};
