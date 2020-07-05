#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QFontDialog>
#include <QTextEdit>
#include <QSettings>
#include <src/Core/file/file.hpp>
#include <src/Environment/help/help.hpp>
#include <src/Environment/schemes/schemes.hpp>
#include <src/Syntax/syntaxHighlighter.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; class Files; }
QT_END_NAMESPACE

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

private slots:
    void setupFont();
    void zoomIn();
    void zoomOut();

private:
    void setSettings();
    void getSettings();
    void initAppearance();
    void initHighlighter();
    void initConnects(QWidget * );
    void initShortcuts(QWidget * );
    Ui::Editor * ui{};
    Highlighter * highlighter;
    QWidget * helpWindow = new QWidget;
    Help * help = new Help(helpWindow);
    Files * files = new Files(ui);
    Schemes * themes = new Schemes(ui, helpWindow);
    QSettings * settings = new QSettings("mini", "mini", this);
};
