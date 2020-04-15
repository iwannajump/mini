#include "syntaxHighlighter.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QPlainTextEdit>
#include "QPalette"



void mySyntaxHighLighter::highlightBlock(const QString &text) {

      enum { NormalState = -1, CStyleComment };


          int state = previousBlockState();
          int start = 0;


/* * * * * * * * * * * * *  NUMBERS * * * * * * * * * * * * * * */

        for (int i = 0; i < text.length(); ++i) {

            if (text.at(i).isNumber()) {
                setFormat(i, 1, "#D33682");
            }
        }


/* * * * * * * * * * * * *  COMMENTS * * * * * * * * * * * * * * */

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
                    //break;
                }
                else if (text.mid(i, 2) == "/*") {

                    start = i;
                    state = CStyleComment;
                }
            }

        }



/* * * * * * * * * * * * *  ANGLE BRACKETS * * * * * * * * * * * * * * */


        for (int i = 0; i < text.length(); ++i)
        {

            if (state == CStyleComment) {

                if (text.mid(i, 1) == ">") {

                    state = NormalState;
                    setFormat(start, i - start + 1, "#859900");
                }
            }
            else {
                if (text.mid(i, 1) == "<") {

                    start = i;
                    state = CStyleComment;
                }
            }

        }

/* * * * * * * * * * * * *  " " * * * * * * * * * * * * * * */


    for (int i = 0; i < text.length(); ++i)
    {

        if (state == CStyleComment) {

            if (text.mid(i, 1) == '"') {

                state = NormalState;
                setFormat(start, i - start + 1, "#859900");
            }
        }
        else {
            if (text.mid(i, 1) == '"') {

                start = i;
                state = CStyleComment;
            }
        }

    }

/* * * * * * * * * * * * *  KEYWORDS * * * * * * * * * * * * * * */


        /* DATA TYPES */
        QString typeInt = "int ";
        QString typeShort = "short ";
        QString typeLong = "long ";
        QString typeFloat = "float ";
        QString typeDouble = "double ";
        QString typeChar = "char ";
        QString typeBoolean = "bool ";
        QString typeAuto = "auto ";
        QString keyUnsigned = "unsigned ";

        /* KEYWORDS */
        QString Kclass = "class ";
        QString Kbreak = "break ";
        QString Kcase = "case ";
        QString Kcatch = "catch ";
        QString Kconst = "const ";
        QString Kcontinue = "continue ";
        QString Kdefault = "default ";
        QString Kdelete = "delete ";
        QString Kdo = "do ";
        QString Kelse = "else ";
        QString Kenum = "enum ";
        QString Kexplicit = "explicit ";
        QString Kexport = "export ";
        QString Kextern = "extern";
        QString Kfalse = "false ";
        QString Kfor = "for ";
        QString Kfriend = "friend ";
        QString Kgoto = "goto ";
        QString Kif = "if ";
        QString Kinclude = "#include ";
        QString Kinline = "inline ";
        QString Kmutable = "mutable ";
        QString Knamespace = "namespace ";
        QString Knew = "new ";
        QString Knoexcept = "noexcept ";
        QString Knot = "not ";
        QString Knullptr = "nullptr ";
        QString Koperator = "operator ";
        QString Kor = "or ";
        QString Kprivate = "private ";
        QString Kprotected = "protected ";
        QString Kpublic = "public ";
        QString Kregister = "register ";
        QString Kreturn = "return ";
        QString Ksigned = "signed ";
        QString Ksizeof = "sizeof ";
        QString Kstatic = "static ";
        QString Kstruct = "struct ";
        QString Kswitch = "switch ";
        QString Ktemplate = "template ";
        QString Kthis = "this ";
        QString Kthread = "thread ";
        QString Kthrow = "throw ";
        QString Ktrue = "true ";
        QString Ktry = "try ";
        QString Ktypedef = "typedef ";
        QString Ktypeid = "typeid ";
        QString Ktypename = "typename ";
        QString Kunion = "union ";
        QString Kusing = "using ";
        QString Kvirtual = "virtual ";
        QString Kvoid = "void ";
        QString Kvolatile = "volatile ";
        QString Kwchar_t = "wchar_t ";
        QString Kwhile = "while ";
        QString Kxor = "xor ";



        for (int i = 0; i < text.length(); ++i) {


            /* ACCESS MODIFIERS*/
            if (text.mid(i, Kstatic.size()) == "static " || text.mid(i, Kprivate.size()) == "private " ||
                text.mid(i, Kpublic.size()) == "public ") {
                setFormat(i, 7, Qt::darkCyan);
                //break
            }
            if (text.mid(i, Kprotected.size()) == "protected ") {
                setFormat(i, Kprotected.size(), Qt::darkCyan);
            }

            /* DADA TYPES */

            //            if (text.startsWith(typeInt)) {
            //                setFormat(i, typeInt.size(), Qt::darkYellow);
            //                break;
            //            }

            if (text.mid(i, typeInt.size()) == "int ")
                setFormat(i,typeInt.size(), Qt::darkYellow);

            if (text.mid(i, typeChar.size()) == "char ")
                setFormat(i,typeChar.size(), Qt::darkYellow);

            if (text.mid(i, typeShort.size()) == "short ")

                setFormat(i,typeShort.size(), Qt::darkYellow);
            if (text.mid(i, typeLong.size()) == "long ")

                setFormat(i,typeLong.size(), Qt::darkYellow);
            if (text.mid(i, typeAuto.size()) == "auto ")

                setFormat(i,typeAuto.size(), Qt::darkYellow);
            if (text.mid(i, typeFloat.size()) == "float ")

                setFormat(i,typeFloat.size(), Qt::darkYellow);
            if (text.mid(i, typeDouble.size()) == "double ")

                setFormat(i,typeDouble.size(), Qt::darkYellow);

            if (text.mid(i, typeBoolean.size()) == "bool ")
                setFormat(i,typeBoolean.size(), Qt::darkYellow);

            if (text.startsWith("#include")) {
                setFormat(i, 8, "#0E6A87");
                break;
            }




//            if (text.mid(i, Kinclude.size()) == "#include ") {
//                setFormat(i, Kinclude.size(), "#0E6A87");
//            }
        }
}

//void mySyntaxHighLighter::highlightCurrentLine()
//{
//    QList<QTextEdit::ExtraSelection> extraSelections;

//    if (!isReadOnly()) {
//        QTextEdit::ExtraSelection selection;

//        QColor lineColor = QColor(Qt::yellow).lighter(160);

//        selection.format.setBackground(lineColor);
//        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
//        selection.cursor = textCursor();
//        selection.cursor.clearSelection();
//        extraSelections.append(selection);
//    }

//    setExtraSelections(extraSelections);
//}
