#include "appearance/colorDataTypes.hpp"
#include "syntaxHighlighter/syntaxHighlighter.hpp"
#include "ui_mainwindow.h"

#include <QRegularExpression>


void mySyntaxHighLighter::highlightBlock(const QString &text) {

    enum {
        NormalState = -1, CStyleComment
    };


    int state = previousBlockState();
    int start = 0;



/* * * * * * * * * * * * *  NUMBERS * * * * * * * * * * * * * * */

    for (int i = 0; i < text.length(); ++i) {

        if (text.at(i).isNumber()) {
            setFormat(i, 1, "#D33682");
        }
    }


/* * * * * * * * * * * * *  COMMENTS * * * * * * * * * * * * * * */

    for (int i = 0; i < text.length(); ++i) {

        if (state == CStyleComment) {

            if (text.mid(i, 2) == "*/") {

                state = NormalState;
                setFormat(start, i - start + 2, "#707593");
            }
        }
        else {
            if (text.mid(i, 2) == "//") {

                setFormat(i, text.length() - i, "#707593");

            } else if (text.mid(i, 2) == "/*") {

                start = i;
                state = CStyleComment;
            }
        }

    }



/* * * * * * * * *   ANGLE BRACKETS  & DOUBLE QUOTES   * * * * * * * * */


    for (int i = 0; i < text.length(); ++i) {

        if (state == CStyleComment) {

            if (text.mid(i, 1) == ">") {

                state = NormalState;
                setFormat(start, i - start + 1, "#859900");
            }
        } else {
            if (text.mid(i, 1) == "<") {

                start = i;
                state = CStyleComment;
            }
        }

    }


    for (int i = 0; i < text.length(); ++i) {

        if (state == CStyleComment) {

            if (text.mid(i, 1) == '"') {

                state = NormalState;
                setFormat(start, i - start + 1, "#859900");
            }
        } else {
            if (text.mid(i, 1) == '"') {

                start = i;
                state = CStyleComment;
            }
        }

    }

/* * * * * * * * * * * * *  KEYWORDS * * * * * * * * * * * * * * */


    for (int i = 0; i < text.length(); ++i) {


        /* ACCESS MODIFIERS*/
        if (text.mid(i, Kstatic.size()) == "static ")
            setFormat(i, Kstatic.size(), Qt::darkCyan);

        if (text.mid(i, Kprivate.size()) == "private ")
            setFormat(i, Kprivate.size(), Qt::darkCyan);

        if (text.mid(i, Kpublic.size()) == "public ")
            setFormat(i, Kpublic.size(), Qt::darkCyan);

        if (text.mid(i, Kprotected.size()) == "protected ")
            setFormat(i, Kprotected.size(), Qt::darkCyan);

        /* DATA TYPES */

        if (text.mid(i, typeInt.size()) == "int ")
            setFormat(i, typeInt.size(), Qt::darkYellow);

        if (text.mid(i, typeChar.size()) == "char ")
            setFormat(i, typeChar.size(), Qt::darkYellow);

        if (text.mid(i, typeShort.size()) == "short ")
            setFormat(i, typeShort.size(), Qt::darkYellow);

        if (text.mid(i, typeLong.size()) == "long ")
            setFormat(i, typeLong.size(), Qt::darkYellow);

        if (text.mid(i, typeAuto.size()) == "auto ")
            setFormat(i, typeAuto.size(), Qt::darkYellow);

        if (text.mid(i, typeFloat.size()) == "float ")
            setFormat(i, typeFloat.size(), Qt::darkYellow);

        if (text.mid(i, typeDouble.size()) == "double ")
            setFormat(i, typeDouble.size(), Qt::darkYellow);

        if (text.mid(i, typeBoolean.size()) == "bool ")
            setFormat(i, typeBoolean.size(), Qt::darkYellow);

        if (text.mid(i, typeString.size()) == "string ")
            setFormat(i, typeString.size(), Qt::darkYellow);

        if (text.mid(i, typeVoid.size()) == "void ")
            setFormat(i, typeVoid.size(), Qt::darkYellow);

        if (text.mid(i, typeClass.size()) == "class ")
            setFormat(i, typeClass.size(), Qt::darkYellow);

        if (text.mid(i, typeEnum.size()) == "enum ")
            setFormat(i, typeEnum.size(), Qt::darkYellow);



        if (text.mid(i, 2) == "<<") {
            setFormat(i, 2, Qt::darkMagenta);
            break;
        }

        if (text.mid(i, 2) == ">>") {
            setFormat(i, 2, Qt::darkMagenta);
            break;
        }



        if (text.mid(i, Kinclude.size()) == "#include ") {

            setFormat(i, Kinclude.size(), "#c7006d");                   //#include




            //setFormat(Kinclude.size() + i, text.length(), "#7c8df2");   //all text after "#include"
        }

        if (text.mid(i, Kdefine.size()) == "#define ") {

            setFormat(i, Kdefine.size(), "#c7006d");                    //#define
            setFormat(Kdefine.size() + i, text.length(), "#7c8df2");    //all text after "#define"
        }

        if (text.mid(i, Kifndef.size()) == "#ifndef ") {

            setFormat(i, Kifndef.size(), "#c7006d");                    //#ifndef
            setFormat(Kifndef.size() + i, text.length(), "#7c8df2");    //all text after "#ifndef"
        }



        if (text.mid(i, Kpragma.size()) == "#pragma ") {

            setFormat(i, Kpragma.size(), "#c7006d");

            if (text.mid(i + Kpragma.size(), pragmaOnce.size()) == "once")
                setFormat(Kpragma.size() + i,  pragmaOnce.size(), "#c7006d");
        }

        if (text.mid(i, pragmaOmp.size()) == "#pragma omp") {

            setFormat(i, pragmaOmp.size(), "#c7006d");

            if (text.mid(i + pragmaOmp.size() + 1, pragmaOmpFor.size()) == "for")
                setFormat(pragmaOmp.size() + i + 1, pragmaOmpFor.size(), "#c7006d");

            if (text.mid(i + pragmaOmp.size() + 1, pragmaOmpFlush.size()) == "flush")
                setFormat(pragmaOmp.size() + i + 1, pragmaOmpFlush.size(), "#c7006d");

            if (text.mid(i + pragmaOmp.size() + 1, pragmaOmpAtomic.size()) == "atomic")
                setFormat(pragmaOmp.size() + i + 1, pragmaOmpAtomic.size(), "#c7006d");
        }


    }   //for (line 60)
} //void mySyntaxHighLighter::highlightBlock


void mySyntaxHighLighter::highlightCurrentLine() {
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!this->edit->isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = this->edit->textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    this->edit->setExtraSelections(extraSelections);
}


mySyntaxHighLighter::mySyntaxHighLighter(QTextDocument *document, QPlainTextEdit *edit) :
        QSyntaxHighlighter(document) {
    this->edit = edit;
    connect(edit, SIGNAL(*edit->cursorPositionChanged()), this, SLOT(mySyntaxHighLighter::highlightCurrentLine));
}


