#include "mainwindow.hpp"
#include "syntaxHighlighter/syntaxHighlighter.hpp"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtCore/QProcessEnvironment>
#include "themes.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->TextEdit);

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    auto HOME = env.value("HOME", "/root");
    cfg = new configurator(HOME + "/.config/mini/config.json");
    cfg->loadConfig(&this->config);
    qDebug() << "Find:"        << config.font_name;
    qDebug() << "Font size:"   << config.font_size;
    qDebug() << "Color scheme" << config.color_scheme;

    connect(ui->actionExit,     SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(ui->actionSave,     SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionOpen,     SIGNAL(triggered()), this, SLOT(checkOpenFile()));
    connect(ui->actionNew,      SIGNAL(triggered()), this, SLOT(checkNewFile()));
    connect(ui->actionlight,    SIGNAL(triggered()), this, SLOT(setColorSchemeLight()));
    connect(ui->actiondark,     SIGNAL(triggered()), this, SLOT(setColorSchemeDark()));
    connect(ui->actionsolarized,SIGNAL(triggered()), this, SLOT(setColorSchemeSolarized()));
    connect(ui->QAChangeFont,   SIGNAL(triggered()), this, SLOT(setCurrentFont()));

    QFontMetrics metrics(font());
    ui->TextEdit->setTabStopWidth(4 * metrics.width('a'));

    highlighter = new Highlighter(ui->TextEdit->document());
    highlighter->highlightBlock(ui->TextEdit->toPlainText());

    InitColorSchemes();
    shortcuts();
}

MainWindow::~MainWindow()
{
    delete ui;
}




