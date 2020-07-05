#pragma once

#include <ui_editor.h>

class Schemes : public QObject
{
    Q_OBJECT

public:
    Schemes
    (Ui::Editor * window_ui, QWidget * window_widget);

private:
    void textEditStyle   (QString bg, QString color, QString border);
    void menuBarStyle    (QString bg, QString color, QString border);
    void statusBarStyle  (QString bg, QString color, QString border);
    void helpWindowStyle (QString bg, QString color, QString border);
    Ui::Editor * ui;
    QWidget * widget;

public slots:
    void setColorSchemeLight    ();
    void setColorSchemeDark     ();
    void setColorSchemeSolarized();
};
