/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionLightScheme;
    QAction *actionDarkScheme;
    QAction *actionSolarizedTheme;
    QAction *actionHelp;
    QAction *actionFont;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *textEdit;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuSettings;
    QMenu *menuColorScheme;
    QMenu *menuHelp;

    void setupUi(QMainWindow *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->resize(939, 615);
        actionNew = new QAction(Editor);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew->setCheckable(false);
        actionOpen = new QAction(Editor);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(Editor);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(Editor);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(Editor);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionLightScheme = new QAction(Editor);
        actionLightScheme->setObjectName(QString::fromUtf8("actionLightScheme"));
        actionDarkScheme = new QAction(Editor);
        actionDarkScheme->setObjectName(QString::fromUtf8("actionDarkScheme"));
        actionSolarizedTheme = new QAction(Editor);
        actionSolarizedTheme->setObjectName(QString::fromUtf8("actionSolarizedTheme"));
        actionFont = new QAction(Editor);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionHelp = new QAction(Editor);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralwidget = new QWidget(Editor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        Editor->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Editor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Editor->setStatusBar(statusBar);
        menuBar = new QMenuBar(Editor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 939, 24));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuColorScheme = new QMenu(menuSettings);
        menuColorScheme->setObjectName(QString::fromUtf8("menuColorScheme"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Editor->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addSeparator();
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionSave_as);
        menu->addAction(actionExit);
        menuSettings->addAction(menuColorScheme->menuAction());
        menuSettings->addAction(actionFont);
        menuColorScheme->addAction(actionLightScheme);
        menuColorScheme->addAction(actionDarkScheme);
        menuColorScheme->addAction(actionSolarizedTheme);
        menuHelp->addAction(actionHelp);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Editor)
    {
        Editor->setWindowTitle(QCoreApplication::translate("Editor", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("Editor", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("Editor", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("Editor", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("Editor", "Save as", nullptr));
        actionExit->setText(QCoreApplication::translate("Editor", "Exit", nullptr));
        actionLightScheme->setText(QCoreApplication::translate("Editor", "light", nullptr));
        actionDarkScheme->setText(QCoreApplication::translate("Editor", "dark", nullptr));
        actionSolarizedTheme->setText(QCoreApplication::translate("Editor", "solarized", nullptr));
        actionFont->setText(QCoreApplication::translate("Editor", "Font", nullptr));
        menu->setTitle(QCoreApplication::translate("Editor", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("Editor", "Edit", nullptr));
        menuColorScheme->setTitle(QCoreApplication::translate("Editor", "Color scheme", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Editor", "Help", nullptr));
        actionHelp->setText(QCoreApplication::translate("Editor", "Open Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
