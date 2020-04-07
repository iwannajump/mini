#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
                                        , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    shortcuts();
    this->setCentralWidget(ui->TextEdit);


    connect(ui->actionExit,     SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionSave,     SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionOpen,     SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionNew,      SIGNAL(triggered()), this, SLOT(newFile()));


    connect(ui->actionlight,    SIGNAL(triggered()), this, SLOT(setColorSchemeLight()));
    connect(ui->actiondark,     SIGNAL(triggered()), this, SLOT(setColorSchemeDark()));
    connect(ui->actionsolarized,SIGNAL(triggered()), this, SLOT(setColorSchemeSolarized()));

}

MainWindow::~MainWindow() {

    delete ui;

}





