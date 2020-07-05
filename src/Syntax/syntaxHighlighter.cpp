#include "src/Syntax/syntaxHighlighter.hpp"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

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
}
