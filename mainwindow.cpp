#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
                                        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shortcuts();
    this->setCentralWidget(ui->TextEdit);


    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));


}

MainWindow::~MainWindow()
{
    delete ui;

}





