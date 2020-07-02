#pragma once

#include <QSyntaxHighlighter>
#include <QMap>
#include <QPlainTextEdit>
#include <QRegularExpression>
#include <QTextEdit>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit Highlighter(QTextDocument *parent = 0);
    void highlightBlock(const QString &text) override;

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
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
};

