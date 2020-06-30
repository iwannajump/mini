#include "src/Core/mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initAppearance();
    initConnects();
    initShortcuts();
    initHighlighter();    
}

MainWindow::~MainWindow()
{
    delete themes;
    delete files;
    delete highlighter;
    delete ui;
}
