#pragma once

#include <QSyntaxHighlighter>
#include <QMap>
#include <QPlainTextEdit>
#include "QTextEdit"

class mySyntaxHighLighter : public QSyntaxHighlighter {
public:
    mySyntaxHighLighter(QTextDocument *document, QPlainTextEdit *edit);;

    ~ mySyntaxHighLighter() {};

    void highlightBlock(const QString &text);

    void highlightCurrentLine();

    QPlainTextEdit *edit;
    QMap<QString, QColor> items;
};
