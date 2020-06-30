#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QFontDialog>
#include <QTextEdit>
#include <ui_mainwindow.h>
#include <src/Core/file/file.hpp>
#include <src/Environment/schemes/schemes.hpp>
#include <src/moduleSyntax/syntaxHighlighter.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setupFont();
    void zoomIn();
    void zoomOut();

private:
    void initConnects();
    void initAppearance();
    void initShortcuts();
    void initHighlighter();
    Ui::MainWindow * ui{};
    Highlighter * highlighter;
    Files * files = new Files;
    Schemes * themes = new Schemes;
};
