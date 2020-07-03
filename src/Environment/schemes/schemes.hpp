#pragma once

#include <ui_mainwindow.h>

class Schemes : public QObject
{
    Q_OBJECT

public slots:
    QString setColorSchemeLight(Ui::Editor * );
    QString setColorSchemeDark(Ui::Editor * );
    QString setColorSchemeSolarized(Ui::Editor * );
};
