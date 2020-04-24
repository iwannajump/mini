#include "src/moduleSyntax/syntaxHighlighter.hpp"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QMap>


Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent )
{
    HighlightingRule rule;

    keywordFormat.setForeground(QColor(125, 65, 130));
    const QString keywordPatterns[] =
    {
        QString("\\bclass\\b"), QString("\\bconst\\b"), QString("\\benum\\b"),
        QString("\\bexplicit\\b"), QString("\\bfriend\\b"), QString("\\binline\\b"),
        QString("\\boperator\\b"), QString("\\bprivate\\b"), QString("\\bgoto\\b"),
        QString("\\bprotected\\b"), QString("\\bpublic\\b"), QString("\\bsignals\\b"),
        QString("\\bsigned\\b"), QString("\\bslots\\b"), QString("\\bstatic\\b"),
        QString("\\btypedef\\b"), QString("\\btypename\\b"), QString("\\bunion\\b"),
        QString("\\bunsigned\\b"), QString("\\bvirtual\\b"), QString("\\bvolatile\\b"),
        QString("\\busing\\b"), QString("\\bif\\b"), QString("\\belse\\b"),
        QString("\\belif\\b"), QString("\\bwhile\\b"), QString("\\busing\\b"),
        QString("\\boverride\\b"), QString("\\bnullptr\\b"), QString("\\bNULL\\b"),
        QString("\\bfor\\b"), QString("\\breturn\\b"), QString("\\bthis\\b"),
        QString("\\bfalse\\b"), QString("\\btrue\\b"), QString("\\bnullptr\\b")
    };

    for (const QString &pattern : keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    dataTypeFormat.setForeground(QColor(65, 118, 130));
    const QString dataTypes[] =
    {
        QString("\\bchar\\b"), QString("\\bdouble\\b"), QString("\\bint\\b"),
        QString("\\blong\\b"), QString("\\bshort\\b"), QString("\\bstruct\\b"),
        QString("\\btemplate\\b"), QString("\\bvoid\\b"), QString("\\bbool\\b"),
        QString("\\bnamespace\\b")
    };


    for (const QString &pattern : dataTypes)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = dataTypeFormat;
        highlightingRules.append(rule);
    }

    classFormat.setForeground(QColor(52, 80, 110));
    rule.pattern = QRegularExpression(QString("\\bQ[A-Za-z]+\\b"));                 //Q....
    rule.format = classFormat;
    highlightingRules.append(rule);

    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QString("#(endif|define|ifdef|ifndef|error|endif|include).*"));
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::lightGray);
    rule.pattern = QRegularExpression(QString("<<|>>"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QString("#pragma\\b"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setFontWeight(2);
    quotationFormat.setForeground(QColor(178, 150, 0)); //gold
    rule.pattern = QRegularExpression(QString("\\bmain\\b"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    classFormat.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression(QString("\\<(?:\\\\<|.)*?\\>"));                             //<...>
    rule.format = classFormat;
    highlightingRules.append(rule);

    classFormat.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression(QString("->|\\.|,|<|\\/|\\+|\\*|-|=|;|:|\\||!|~|\\^|%|"));
    rule.format = classFormat;                                                      //symbols
    highlightingRules.append(rule);

    classFormat.setForeground(Qt::yellow);
    rule.pattern = QRegularExpression(QString("^(\\w+):($|[\\s{1,}])$"));           //tryexec: (goto label)
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression(QString("[0-9]"));                            //123456789
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(QColor(115, 200, 130));    //mint
    rule.pattern = QRegularExpression(QString("\"(?:\\\"|.)*?\""));                  //"text"
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(QColor(115, 200, 130));   //mint
    rule.pattern = QRegularExpression(QString("\'(?:\\\'|.)*?\'"));                 //'text'
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegularExpression(QString("//.*"));                             //single line comment
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::darkGray);

    commentStartExpression = QRegularExpression(QString("/\\*"));
    commentEndExpression = QRegularExpression(QString("\\*/"));                     //multiline comment
}

void Highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : qAsConst(highlightingRules))
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);


    while (startIndex >= 0)
    {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

