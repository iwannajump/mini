#include "src/Core/mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    highlighter = new Highlighter(ui->TextEdit->document());
    highlighter->highlightBlock(ui->TextEdit->toPlainText());
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
