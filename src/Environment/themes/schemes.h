#ifndef THEMES_H
#define THEMES_H

#include <QObject>
#include <ui_mainwindow.h>

class Schemes : public QObject
{
    Q_OBJECT
public:
    Schemes(){};

public slots:
    void setColorSchemeLight(Ui::MainWindow * );
    void setColorSchemeDark(Ui::MainWindow * );
    void setColorSchemeSolarized(Ui::MainWindow * );
};

#endif // THEMES_H
