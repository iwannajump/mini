//
// Created by dmitry on 4/17/20.
//

#pragma once

#include <QString>
#include <QtCore/QMap>

struct colors
{
    QString bkg, clr, brd;
    colors();
    colors(const QString &_bkg, const QString &_clr, const QString &_brd);
    QString str();
};

class theme
{
public:
    theme(const colors &text_edit, const colors &menu_bar, const colors &status_bar);
    colors textEditColors;
    colors menuBarColors;
    colors statusBarColors;
};

theme* getColorScheme(const QString &name);

void InitColorSchemes();
