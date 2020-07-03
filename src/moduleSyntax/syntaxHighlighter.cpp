#include "src/moduleSyntax/syntaxHighlighter.hpp"
#include "ui_mainwindow.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    quotationFormat.setForeground(QColor(125, 65, 130));
    const QString keywordPatterns[] =
    {
        "\\bclass\\b",      "\\bconst\\b",      "\\benum\\b",
        "\\bexplicit\\b",   "\\bfriend\\b",     "\\binline\\b",
        "\\boperator\\b",   "\\bgoto\\b",       "\\bsignals\\b",
        "\\bsigned\\b",     "\\bslots\\b",      "\\bstatic\\b",
        "\\btypedef\\b",    "\\btypename\\b",   "\\bunion\\b",
        "\\bunsigned\\b",   "\\bvolatile\\b",   "\\busing\\b",
        "\\bif\\b",         "\\belse\\b",       "\\belif\\b",
        "\\bwhile\\b",      "\\busing\\b",      "\\boverride\\b",
        "\\bnullptr\\b",    "\\bNULL\\b",       "\\bfor\\b",
        "\\breturn\\b",     "\\bthis\\b",       "\\bfalse\\b",
        "\\btrue\\b",       "\\bnullptr\\b"
    };

    quotationFormat.setForeground(QColor(65, 118, 130));
    const QString dataTypes[] =
    {
        "\\bchar\\b",       "\\bdouble\\b",     "\\bint\\b",
        "\\blong\\b",       "\\bshort\\b",      "\\bstruct\\b",
        "\\btemplate\\b",   "\\bvoid\\b",       "\\bbool\\b",
        "\\bnamespace\\b"
    };

    quotationFormat.setForeground(QColor(115, 160, 155));
    const QString accessModifiers[]
    {
        "\\bprotected\\b",  "\\bpublic\\b",     "\\bvirtual\\b",
        "\\bprivate\\b"
    };

    for (const QString &pattern : keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = quotationFormat;
        highlightingRules.append(rule);
    }

    for (const QString &pattern : dataTypes)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = quotationFormat;
        highlightingRules.append(rule);
    }

    for (const QString &pattern : accessModifiers)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = quotationFormat;
        highlightingRules.append(rule);
    }

    HighlightLexeme(rule, QColor(178, 150, 0),  "\\bmain\\b");
    HighlightLexeme(rule, QColor(52, 80, 110),  "\\bQ[A-Za-z]+\\b");    //Qt classes
    HighlightLexeme(rule, QColor(115, 200, 130),"\"(?:\\\"|.)*?\"");    //"text"
    HighlightLexeme(rule, QColor(115, 200, 130),"\'(?:\\\'|.)*?\'");   //'text'
    HighlightLexeme(rule, QColor(115, 160, 155),"^(\\w+):$");        //tryexec: (goto label)
    HighlightLexeme(rule, Qt::darkYellow,       "->|\\.|,|<|\\/|\\+|\\*|-|=|;|:|\\||!|~|\\^|%|&"); //symbols
    HighlightLexeme(rule, Qt::darkYellow,       "\\<(?:\\\\<|.)*?\\>");       //<...>
    HighlightLexeme(rule, Qt::darkMagenta,      "#(endif|define|ifdef|ifndef|error|undef|include).*");
    HighlightLexeme(rule, Qt::darkMagenta,      "#pragma\\b");
    HighlightLexeme(rule, Qt::darkMagenta,      "<<|>>");
    HighlightLexeme(rule, Qt::darkGray,         "//.*");
    HighlightLexeme(rule, Qt::darkGreen,        "[0-9]");

    commentStartExpression = QRegularExpression(QString("/\\*"));

    commentEndExpression = QRegularExpression(QString("\\*/"));

    multiLineCommentFormat.setForeground(Qt::darkGray);
}

void Highlighter::HighlightLexeme
    (HighlightingRule rule, QColor color, QString regexp)
{
    quotationFormat.setForeground(color);
    rule.pattern = QRegularExpression(QString(regexp));
    rule.format = quotationFormat;
    highlightingRules.append(rule);
}

void Highlighter::highlightBlock
    (const QString &text)
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
