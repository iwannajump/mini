#include "src/Syntax/syntaxHighlighter.hpp"

void Highlighter::cppHighlight()
{
    HighlightingRule rule;

    keywordFormat.setForeground(QColor(125, 65, 130));
    const QString keywordPatterns[] =
    {
        "\\bclass\\b",      "\\bconst\\b",      "\\benum\\b",
        "\\bexplicit\\b",   "\\bfriend\\b",     "\\binline\\b",
        "\\boperator\\b",   "\\bgoto\\b",       "\\bsignals\\b",
        "\\bslots\\b",      "\\bstatic\\b",     "\\bnullptr\\b"
        "\\btypedef\\b",    "\\btypename\\b",   "\\bunion\\b",
        "\\bvolatile\\b",   "\\busing\\b",      "\\btrue\\b",
        "\\bif\\b",         "\\belse\\b",       "\\belif\\b",
        "\\bwhile\\b",      "\\busing\\b",      "\\boverride\\b",
        "\\bnullptr\\b",    "\\bNULL\\b",       "\\bfor\\b",
        "\\breturn\\b",     "\\bthis\\b",       "\\bfalse\\b",
    };

    dataTypeFormat.setForeground(QColor(100, 150, 90));
    const QString dataTypes[] =
    {
        "\\bchar\\b",       "\\bdouble\\b",     "\\bint\\b",
        "\\blong\\b",       "\\bshort\\b",      "\\bstruct\\b",
        "\\btemplate\\b",   "\\bvoid\\b",       "\\bbool\\b",
        "\\bnamespace\\b",  "\\bunsigned\\b",   "\\bsigned\\b"
    };

    accessModifierFormat.setForeground(QColor(115, 160, 255));
    const QString accessModifiers[]
    {
        "\\bprotected\\b",  "\\bpublic\\b",     "\\bvirtual\\b",
        "\\bprivate\\b"
    };

    for (const QString &pattern : keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    for (const QString &pattern : dataTypes)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = dataTypeFormat;
        highlightingRules.append(rule);
    }

    for (const QString &pattern : accessModifiers)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = accessModifierFormat;
        highlightingRules.append(rule);
    }

    HighlightLexeme(rule, Qt::yellow,           "[0-9]");
    HighlightLexeme(rule, Qt::darkMagenta,      "<<|>>");
    HighlightLexeme(rule, Qt::darkMagenta,      "#pragma\\b");
    HighlightLexeme(rule, Qt::darkMagenta,      "#(define|endif|ifdef|ifndef|error|undef|include).*");
    HighlightLexeme(rule, Qt::darkYellow,       "\\.|,|<|>|\\/|\\+|\\*|-|=|;|:|\\||!|~|\\^|%|&"); //symbols
    HighlightLexeme(rule, Qt::darkYellow,       "<(?:\\<|.)*?>"); //<...>
    HighlightLexeme(rule, QColor(115, 160, 155),"^(\\w+):$"); //tryexec: (goto label)
    HighlightLexeme(rule, QColor(115, 200, 130),"\"(?:\\\"|.)*?\""); //"text"
    HighlightLexeme(rule, QColor(115, 200, 130),"\'(?:\\\'|.)*?\'"); //'text'
    HighlightLexeme(rule, QColor(150, 150, 150),"//.*");
    HighlightLexeme(rule, QColor(52,  80,  110),"\\bQ[A-Za-z]+\\b"); //Qt classes
    HighlightLexeme(rule, QColor(178, 150, 0),  "\\bmain\\b");

    commentStartExpression = QRegularExpression("/\\*");

    commentEndExpression = QRegularExpression("\\*/");

    multiLineCommentFormat.setForeground(Qt::darkGray);
}
