#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QFontDialog>
#include <src/moduleSyntax/syntaxHighlighter.hpp>
#include "ui_mainwindow.h"
#include "file/file.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class File; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setColorSchemeLight();
    void setColorSchemeDark();
    void setColorSchemeSolarized();
    void setCurrentFont();

private:
    Ui::MainWindow * ui{};
    void initConnects();
    void initAppearance();
    void initShortcuts();
    QShortcut * CtrlQ{}; //exit
    QShortcut * CtrlS{}; //save
    QShortcut * CtrlN{}; //new file
    QShortcut * CtrlO{}; //open
    QTextEdit * editor;
    Highlighter * highlighter;
    Files * files = new Files;
};
