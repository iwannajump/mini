#include "src/Core/mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initAppearance();
    initConnects();
    initShortcuts();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete highlighter;
    delete files;
}
