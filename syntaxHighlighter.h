#pragma once

#include <QSyntaxHighlighter>
#include <QMap>
#include <QPlainTextEdit>
#include "QTextEdit"

class mySyntaxHighLighter: public QSyntaxHighlighter
{
public:
  mySyntaxHighLighter(QTextDocument* document):
  QSyntaxHighlighter(document) {};
  ~ mySyntaxHighLighter() {};

  void highlightBlock(const QString &text);
  void highlightCurrentLine();

  QMap<QString, QColor> items;
};
