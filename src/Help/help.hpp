#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QLabel>
#include "ui_help.h"

class Help : public QWidget
{
    Q_OBJECT
public:
    Help(QWidget * helpWindow = 0);
    void showHelpWindow();

private:
    QWidget * window = new QWidget;
    Ui::HelpWindow * ui = new Ui::HelpWindow;

};

#endif // HELP_H
