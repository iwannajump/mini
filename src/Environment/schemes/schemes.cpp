#include "schemes.hpp"

void Schemes::textEditStyle
    (Ui::Editor * ui, QString bg, QString color, QString border)
{
    ui->textEdit->setStyleSheet
        ("background-color: " + bg + ";"
        "color: " +  color + ";"
        "border-color: " + border );
}
void Schemes::menuBarStyle
    (Ui::Editor * ui, QString bg, QString color, QString border)
{
    ui->menuBar->setStyleSheet
        ("background-color: " + bg + ";"
        "color: " +  color + ";"
        "border-color: " + border );
}
void Schemes::statusBarStyle
    (Ui::Editor * ui, QString bg, QString color, QString border)
{
    ui->statusBar->setStyleSheet
        ("background-color: " + bg + ";"
        "color: " +  color + ";"
        "border-color: " + border );
}

void Schemes::setColorSchemeLight(Ui::Editor * ui)
{
    textEditStyle (ui, "#ffffff", "#000000", "#000000");
    menuBarStyle  (ui, "#ffffff", "#000000", "#000000");
    statusBarStyle(ui, "#ffffff", "#000000", "#000000");
}

void Schemes::setColorSchemeDark(Ui::Editor * ui)
{
    textEditStyle (ui, "#000000", "#dadada", "#dadada");
    menuBarStyle  (ui, "#0f0f0f", "#dadada", "#ffffff");
    statusBarStyle(ui, "#0f0f0f", "#839496", "#ffffff");
}

void Schemes::setColorSchemeSolarized(Ui::Editor * ui)
{
    textEditStyle (ui, "#002b36", "#839496", "#ffffff");
    menuBarStyle  (ui, "#001c24", "#839496", "#ffffff");
    statusBarStyle(ui, "#001c24", "#839496", "#ffffff");
}
