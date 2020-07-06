#include "schemes.hpp"

Schemes::Schemes(Ui::Editor * window_ui, QWidget * window_widget)
{
    ui = window_ui;
    widget = window_widget;
}

void Schemes::textEditStyle
    (QString bg, QString color, QString border)
{
    ui->textEdit->setStyleSheet
        ("background-color: " + bg + ";"
        "color: " +  color + ";"
        "border-color: " + border );
}

void Schemes::menuBarStyle
    (QString bg, QString color, QString border)
{
    ui->menuBar->setStyleSheet
        ("background-color: " + bg + ";"
        "color: " +  color + ";"
        "border-color: " + border );
}

void Schemes::statusBarStyle
    (QString bg, QString color, QString border)
{
    ui->statusBar->setStyleSheet
        ("background-color: " + bg + ";"
        "color: " +  color + ";"
        "border-color: " + border );
}

void Schemes::helpWindowStyle
    (QString bg, QString color, QString border)
{
    widget->setStyleSheet
            ("background-color: " + bg + ";"
            "color: " +  color + ";"
            "border-color: " + border );
}

void Schemes::setColorSchemeLight()
{
    textEditStyle  ("#f0f0f0", "#000000", "#000000");
    menuBarStyle   ("#f0f0f0", "#000000", "#000000");
    statusBarStyle ("#f0f0f0", "#000000", "#000000");
    helpWindowStyle("#f0f0f0", "#000000", "#000000");
}

void Schemes::setColorSchemeDark()
{
    textEditStyle  ("#000000", "#dadada", "#dadada");
    menuBarStyle   ("#0f0f0f", "#dadada", "#ffffff");
    statusBarStyle ("#0f0f0f", "#839496", "#ffffff");
    helpWindowStyle("#0f0f0f", "#839496", "#ffffff");
}

void Schemes::setColorSchemeSolarized()
{
    textEditStyle  ("#002b36", "#839496", "#ffffff");
    menuBarStyle   ("#001c24", "#839496", "#ffffff");
    statusBarStyle ("#001c24", "#839496", "#ffffff");
    helpWindowStyle("#001c24", "#839496", "#ffffff");
}
