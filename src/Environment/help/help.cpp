#include "help.hpp"

Help::Help(QWidget *helpWindow)
{
    window = helpWindow;
}

void Help::showHelpWindow()
{
    window->resize(400, 600);
    window->show();
}
