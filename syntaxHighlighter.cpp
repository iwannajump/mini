#include "syntaxHighlighter.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>


QMap<QString, QColor> items = {
    { "#include ", Qt::red },
    { "int ", Qt::darkGreen },
    { "char ", Qt::darkGreen },
    { "float ", Qt::darkGreen },
    { "double ", Qt::darkGreen },
    { "void ", Qt::darkBlue },
    { "class ", Qt::darkBlue },
    { "namespace ", Qt::darkBlue },
    };

void mySyntaxHighLighter::highlightBlock(const QString &text) {

      enum { NormalState = -1, CStyleComment };


          int state = previousBlockState();
          int start = 0;



        for (int i = 0; i < text.length(); ++i)
        {

            if (state == CStyleComment) {

                if (text.mid(i, 2) == "*/") {

                    state = NormalState;
                    setFormat(start, i - start + 2, Qt::gray);
                }
            }
            else {
                if (text.mid(i, 2) == "//") {

                    setFormat(i, text.length() - i, "#707593");
                    break;
                }
                else if (text.mid(i, 2) == "/*") {

                    start = i;
                    state = CStyleComment;
                }
            }

        }

        for (int i = 0; i < text.length(); ++i) {


        }

        for (int i = 0; i < text.length(); ++i)

            if (text.mid(i, 3) == "int") {
                setFormat(i, 3, Qt::green);
                break;
            }
            else if (text.mid(i, 8) == "#include") {
                setFormat(i, 8, Qt::red);
            }
}
