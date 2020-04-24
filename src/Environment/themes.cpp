//
// Created by dmitry on 4/17/20.
//

#include "src/Environment/themes.h"

colors::colors() = default;
colors::colors(const QString &Background, const QString &Color, const QString &Border)
{
    bkg = Background;
    clr = Color;
    brd = Border;
}
QString colors::str()
{
    QString s = "";
    if (bkg != "")
    {
        s += "background-color: " + bkg + "; ";
    }
    if (clr != "")
    {
        s += "color: " + clr + "; ";
    }
    if (brd != "")
    {
        s += "border-color: " + brd + ";";
    }
    return s;
}

theme::theme(const colors &text_edit, const colors &menu_bar, const colors &status_bar)
{
    textEditColors =  text_edit;
    menuBarColors =   menu_bar;
    statusBarColors = status_bar;
}

QMap<QString, theme*> ColorSchemes;

theme* getColorScheme(const QString &name)
{
    return ColorSchemes[name];
}

void InitColorSchemes()
{
    ColorSchemes["Light"] = new theme(
            colors(
                    "#ffffff",
                    "#000000",
                    ""
            ),
            colors(
                    "#f0f0f0",
                    "#000000",
                    "#000000"
            ),
            colors(
                    "#f0f0f0",
                    "#000000",
                    "#000000"
            )
            );
    ColorSchemes["Dark"] = new theme(
            colors(
                    "#000000",
                    "#dadada",
                    ""
            ),
            colors(
                    "#0f0f0f",
                    "#dadada",
                    "#ffffff"
            ),
            colors(
                    "#000000",
                    "#839496",
                    "#ffffff"
            )
    );
    ColorSchemes["Solarized"] = new theme(
            colors(
                    "#082b36",
                    "#839496",
                    ""
            ),
            colors(
                    "#001c24",
                    "#839496",
                    "#ffffff"
            ),
            colors(
                    "#001c24",
                    "#839496",
                    "#ffffff"
            )
    );
}
