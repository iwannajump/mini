QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Core/appearance.cpp             \
    src/Core/connects.cpp               \
    src/Core/editor.cpp                 \
    src/Core/main.cpp                   \
    src/File/file.cpp                   \
    src/Help/help.cpp                   \
    src/Schemes/schemes.cpp             \
    src/Settings/settings.cpp           \
    src/Shortcuts/shortcuts.cpp         \
    src/Syntax/syntaxHighlighter.cpp    \
    src/Syntax/cppHighlighter.cpp       \

HEADERS += \
    src/Core/editor.hpp                 \
    src/File/file.hpp                   \
    src/Help/help.hpp                   \
    src/Schemes/schemes.hpp             \
    src/Syntax/syntaxHighlighter.hpp    \


FORMS += \
    src/Core/editor.ui                  \
    src/Help/help.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
