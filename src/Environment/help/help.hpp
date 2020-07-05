#ifndef HELP_H
#define HELP_H

#include <QWidget>

class Help : public QWidget
{
    Q_OBJECT
public:
    Help(QWidget * helpWindow = 0);
    void showHelpWindow();
private:
    QWidget * window = new QWidget;
};

#endif // HELP_H
