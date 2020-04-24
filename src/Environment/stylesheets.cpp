#include "ui_mainwindow.h"
#include "src/core/mainwindow.hpp"


#include "themes.h"

void MainWindow::setColorScheme(const QString &name)
{
    theme* s = getColorScheme(name);

    ui->TextEdit->setStyleSheet(s->textEditColors.str());
    ui->menuBar->setStyleSheet(s->menuBarColors.str());
    ui->statusBar->setStyleSheet(s->statusBarColors.str());
}

void MainWindow::setColorSchemeLight()
{

    ui->TextEdit->setStyleSheet("background-color: #ffffff;"
                                "color: #000000;");
    ui->menuBar->setStyleSheet("background-color: #f0f0f0;"
                               "color: #000000;"
                               "border-color: #000000");
    ui->statusBar->setStyleSheet("background-color: #f0f0f0;"
                                 "color: #000000;"
                                 "border-color: #000000");
}

void MainWindow::setColorSchemeDark()
{

    ui->TextEdit->setStyleSheet("background-color: #000000;"
                                "color: #dadada;");
    ui->menuBar->setStyleSheet("background-color: #0f0f0f;"
                               "color: #dadada;"
                               "border-color: #ffffff;"
    );
    ui->statusBar->setStyleSheet("background-color: #000000;"
                                 "color: #839496;"
                                 "border-color: #ffffff;"
    );
}

void MainWindow::setColorSchemeSolarized()
{

    ui->TextEdit->setStyleSheet("background-color: #002b36;"
                                "color: #839496;");
    ui->menuBar->setStyleSheet("background-color: #001c24;"
                               "color: #839496;"
                               "border-color: #ffffff;"
    );
    ui->statusBar->setStyleSheet("background-color: #001c24;"
                                 "color: #839496;"
                                 "border-color: #ffffff;"
    );
}
