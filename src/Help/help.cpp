#include "help.hpp"

Help::Help(QWidget *helpWindow)
{
    window = helpWindow;
}

void Help::showHelpWindow()
{
    ui->setupUi(window);
    window->show();
}
