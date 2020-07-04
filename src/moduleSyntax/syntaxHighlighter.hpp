#pragma once

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit Highlighter(QTextDocument * parent = 0);
    void highlightBlock(const QString & text) override;
    void cppHighlight();

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    void HighlightLexeme(HighlightingRule rule, QColor color, QString regexp);
    QVector<HighlightingRule> highlightingRules;
    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;
    QTextCharFormat dataTypeFormat;
    QTextCharFormat accessModifierFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat multiLineCommentFormat;
};

