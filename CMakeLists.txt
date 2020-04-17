project(mini LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-fpermissive")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(mini syntaxHighlighter)
include_directories(mini behavior)
set(SOURCES
        mainwindow.ui
        mainwindow.cpp
        main.cpp
        behavior/shortcuts.cpp
        syntaxHighlighter/syntaxHighlighter.cpp
        behavior/actions.cpp
        behavior/appearance.cpp
        stylesheets.cpp
        syntaxHighlighter/colorDataTypes.hpp
        configuration/configurator.cpp configuration/configurator.hpp)
add_executable(mini
        ${SOURCES}
        )

target_link_libraries(mini Qt5::Widgets)
