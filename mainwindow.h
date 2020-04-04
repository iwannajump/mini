#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QClipboard>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void shortcuts();

private slots:
    void saveFileAs();
    void openFile();
    void newFile();
    //void copySelection();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    QShortcut *CtrlQ;
    QShortcut *CtrlS;
};
#endif // MAINWINDOW_H
