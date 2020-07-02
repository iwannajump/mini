#include "editor.hpp"

void Editor::saveSettings()
{
    QSettings settings("mini", "mini");
    this->centralWidget()->setFont
            (settings.value("font", QFont()).value<QFont>());
}

void Editor::loadSettings()
{
    QSettings settings("mini", "mini");
    settings.setValue
            ("font", this->centralWidget()->font());
}
