#include "../syntaxHighlighter/colorDataTypes.hpp"
#include "syntaxHighlighter.hpp"
#include "../ui_mainwindow.h"

#include <QRegularExpression>

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::blue);
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatterns[] =
    {
        QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"), QStringLiteral("\\benum\\b"),
        QStringLiteral("\\bexplicit\\b"), QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"),
        QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"), QStringLiteral("\\bprivate\\b"),
        QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"), QStringLiteral("\\bsignals\\b"),
        QStringLiteral("\\bsigned\\b"), QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"),
        QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"), QStringLiteral("\\bunion\\b"),
        QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"), QStringLiteral("\\bvolatile\\b"),
        QStringLiteral("\\busing\\b"), QStringLiteral("\\bif\\b"), QStringLiteral("\\belse\\b"),
        QStringLiteral("\\belif\\b"), QStringLiteral("\\bwhile\\b"), QStringLiteral("\\busing\\b")
    };

    for (const QString &pattern : keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    dataTypeFormat.setForeground(Qt::darkYellow);
    dataTypeFormat.setFontWeight(QFont::Bold);
    const QString dataTypes[] = {
        QStringLiteral("\\bchar\\b"), QStringLiteral("\\bdouble\\b"), QStringLiteral("\\bint\\b"),
        QStringLiteral("\\blong\\b"), QStringLiteral("\\bshort\\b"), QStringLiteral("\\bstruct\\b"),
        QStringLiteral("\\btemplate\\b"), QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bbool\\b"),
    };

    for (const QString &pattern : dataTypes)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = dataTypeFormat;
        highlightingRules.append(rule);
    }

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.format = classFormat;
    highlightingRules.append(rule);

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QStringLiteral("#(endif|define|ifdef|ifndef|error|endif|include|pragma)\\b"));
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression(QStringLiteral("<<|>>"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression(QStringLiteral("#pragma\\b"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    classFormat.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression(QStringLiteral("<.*>"));                  //<...>
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkCyan);
    rule.pattern = QRegularExpression(QStringLiteral("([^ ]*)::"));             //->class<-::something
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkCyan);
    rule.pattern = QRegularExpression(QStringLiteral("([^ ]*)\\."));            //->word<-.something
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression(QStringLiteral("[0-9]"));                 //123456789
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));                //"text"
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression(QStringLiteral("\'.*\'"));                //'text'
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::cyan);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[[^Q]A-Za-z0-9_]+(?=\\()")); //void ->somename<-()
    rule.format = functionFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));              //single line comment
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::darkGray);

    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));          //multiline comment
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
