#pragma once

//#include <ui_mainwindow.h>
#include <ui_editor.h>

class Schemes : public QObject
{
    Q_OBJECT

public slots:
    QString setColorSchemeLight(Ui::Editor * );
    QString setColorSchemeDark(Ui::Editor * );
    QString setColorSchemeSolarized(Ui::Editor * );
};
