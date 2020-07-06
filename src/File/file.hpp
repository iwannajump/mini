#pragma once

#include <ui_editor.h>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

class Files : public QWidget
{
    Q_OBJECT
public:
    Files(Ui::Editor * window_ui);

public slots:
    void saveFile();
    void openFile();
    void checkOpenFile();
    void newFile();
    void checkNewFile();
    void closeFile(QWidget * );
    void appearance(const QString & );

private:
    Ui::Editor * ui;
};
