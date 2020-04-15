#include "mainwindow.h"
#include "syntaxHighlighter.h"
#include "ui_mainwindow.h"
#include "Linenumber.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
                                        , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    shortcuts();
    this->setCentralWidget(ui->TextEdit);

    mySyntaxHighLighter* highlighter = new mySyntaxHighLighter(ui->TextEdit->document());


    connect(ui->actionExit,     SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(ui->actionSave,     SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionOpen,     SIGNAL(triggered()), this, SLOT(checkOpenFile()));
    connect(ui->actionNew,      SIGNAL(triggered()), this, SLOT(checkNewFile()));

    connect(ui->actionlight,    SIGNAL(triggered()), this, SLOT(setColorSchemeLight()));
    connect(ui->actiondark,     SIGNAL(triggered()), this, SLOT(setColorSchemeDark()));
    connect(ui->actionsolarized,SIGNAL(triggered()), this, SLOT(setColorSchemeSolarized()));
    connect(ui->QAChangeFont,   SIGNAL(triggered()), this, SLOT(setCurrentFont()));




}

MainWindow::~MainWindow() {

    delete ui;

}

