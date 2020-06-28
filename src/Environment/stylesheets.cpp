#include "src/Core/mainwindow.hpp"

struct Theme
{
    static void textEditStyle
    (Ui::MainWindow * ui, QString bg, QString color, QString border)
    {
        ui->TextEdit->setStyleSheet
            ("background-color: " + bg + ";"
            "color: " +  color + ";"
            "border-color: " + border );
    }
    static void menuBarStyle
    (Ui::MainWindow * ui, QString bg, QString color, QString border)
    {
        ui->menuBar->setStyleSheet
            ("background-color: " + bg + ";"
            "color: " +  color + ";"
            "border-color: " + border );
    }
    static void statusBarStyle
    (Ui::MainWindow * ui, QString bg, QString color, QString border)
    {
        ui->statusBar->setStyleSheet
            ("background-color: " + bg + ";"
            "color: " +  color + ";"
            "border-color: " + border );
    }
};

void MainWindow::setColorSchemeLight()
{
    Theme::textEditStyle (ui, "#ffffff", "#f0f0f0", "#000000");
    Theme::menuBarStyle  (ui, "#ffffff", "#f0f0f0", "#000000");
    Theme::statusBarStyle(ui, "#ffffff", "#f0f0f0", "#000000");
}

void MainWindow::setColorSchemeDark()
{
    Theme::textEditStyle (ui, "#000000", "#dadada", "#dadada");
    Theme::menuBarStyle  (ui, "#0f0f0f", "#dadada", "#ffffff");
    Theme::statusBarStyle(ui, "#0f0f0f", "#839496", "#ffffff");
}

void MainWindow::setColorSchemeSolarized()
{
    Theme::textEditStyle (ui, "#002b36", "#839496", "#ffffff");
    Theme::menuBarStyle  (ui, "#001c24", "#839496", "#ffffff");
    Theme::statusBarStyle(ui, "#001c24", "#839496", "#ffffff");
}
