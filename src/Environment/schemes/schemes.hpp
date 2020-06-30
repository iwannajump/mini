#pragma once

#include <QObject>
#include <ui_mainwindow.h>

class Schemes : public QObject
{
    Q_OBJECT

public slots:
    void setColorSchemeLight(Ui::MainWindow * );
    void setColorSchemeDark(Ui::MainWindow * );
    void setColorSchemeSolarized(Ui::MainWindow * );
};
