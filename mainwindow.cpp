#include "mainwindow.hpp"
#include "syntaxHighlighter.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    shortcuts();
    this->setCentralWidget(ui->TextEdit);

    //connect(ui->TextEdit, SIGNAL(ui->TextEdit->cursorPositionChanged()), this, SLOT(mySyntaxHighLighter::highlightCurrentLine));


    auto highlighter = new mySyntaxHighLighter(ui->TextEdit->document(), ui->TextEdit);
//    highlighter->highlightCurrentLine();
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(checkOpenFile()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(checkNewFile()));

    connect(ui->actionlight, SIGNAL(triggered()), this, SLOT(setColorSchemeLight()));
    connect(ui->actiondark, SIGNAL(triggered()), this, SLOT(setColorSchemeDark()));
    connect(ui->actionsolarized, SIGNAL(triggered()), this, SLOT(setColorSchemeSolarized()));
    connect(ui->QAChangeFont, SIGNAL(triggered()), this, SLOT(setCurrentFont()));


}

MainWindow::~MainWindow() {

    delete ui;

}
