#pragma once

#include <QSyntaxHighlighter>
#include <QMap>

class mySyntaxHighLighter: public QSyntaxHighlighter
{
public:
  mySyntaxHighLighter(QTextDocument* document):
  QSyntaxHighlighter(document) {};
  ~ mySyntaxHighLighter() {};

  void highlightBlock(const QString &text);

  QMap<QString, QColor> items;
};
