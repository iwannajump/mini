#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QFontDialog>
#include <QTextEdit>
#include <QSettings>
#include <src/Core/file/file.hpp>
#include <src/Environment/schemes/schemes.hpp>
#include <src/moduleSyntax/syntaxHighlighter.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; }
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
    void saveSettings();
    void loadSettings();
    void initAppearance();
    void initHighlighter();
    void initConnects(QWidget * );
    void initShortcuts(QWidget * );
    Ui::Editor * ui{};
    Highlighter * highlighter;
    Files * files = new Files;
    Schemes * themes = new Schemes;
    QSettings * settings = new QSettings("mini", "mini", this);
};
