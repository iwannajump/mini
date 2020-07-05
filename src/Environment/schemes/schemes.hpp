#pragma once

#include <ui_editor.h>

class Schemes : public QObject
{
    Q_OBJECT

private:
    void textEditStyle  (Ui::Editor * ui, QString bg, QString color, QString border);
    void menuBarStyle   (Ui::Editor * ui, QString bg, QString color, QString border);
    void statusBarStyle (Ui::Editor * ui, QString bg, QString color, QString border);

public slots:
    void setColorSchemeLight    (Ui::Editor * );
    void setColorSchemeDark     (Ui::Editor * );
    void setColorSchemeSolarized(Ui::Editor * );
};
