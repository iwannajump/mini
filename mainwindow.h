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
#include <QSyntaxHighlighter>

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
    void setColorSchemeLight();
    void setColorSchemeDark();
    void setColorSchemeSolarized();
    void saveFile();
    void openFile();
    void newFile();
    //void openHelp();


private:
    Ui::MainWindow *ui;
    QString currentFile;
    QShortcut *CtrlQ; //exit
    QShortcut *CtrlS; //save
    QShortcut *CtrlN; //new file
    QShortcut *CtrlO; //open
};
#endif // MAINWINDOW_H
