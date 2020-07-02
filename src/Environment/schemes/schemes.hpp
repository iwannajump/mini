#pragma once

#include <QObject>
#include <ui_mainwindow.h>

class Schemes : public QObject
{
    Q_OBJECT

public slots:
    void setColorSchemeLight(Ui::Editor * );
    void setColorSchemeDark(Ui::Editor * );
    void setColorSchemeSolarized(Ui::Editor * );
};
