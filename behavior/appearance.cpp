#include "../mainwindow.hpp"
#include "../ui_mainwindow.h"


void MainWindow::appearance(QString fileName) {

    setWindowTitle(fileName);
    ui->statusBar->showMessage(fileName);

}


void MainWindow::setCurrentFont() {

    centralWidget()->setFont(QFontDialog::getFont(0, centralWidget()->font()));

}



//void MainWindow::zoomIn() {

//    ui->TextEdit->zoomIn();
//}


//void MainWindow::zoomOut() {

//    ui->TextEdit->zoomOut();
//}


//void MainWindow::zoom()
//{

//    QWheelEvent *e = nullptr;


//        if ((e->modifiers() == Qt::ControlModifier) && (e->delta() > 0))
//        {
//           ui->TextEdit->zoomIn();
//        }
//        else if ((e->modifiers() == Qt::ControlModifier) && (e->delta() < 0) /*&& (fontPS > 8)*/)
//        {
//           ui->TextEdit->zoomOut();
//        }
//}

//void MainWindow::zoom() {

//    const int zoomPerOp = 2;
//    QFont font = ui->TextEdit->font();
//    font.setPointSize(font.pointSize() + zoomPerOp);
//    ui->TextEdit->setFont(font);

//}



