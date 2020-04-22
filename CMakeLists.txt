project(mini LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-fpermissive")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(mini syntaxHighlighter)
include_directories(mini behavior)
include_directories(mini configuration)
include_directories(mini appearance)
include_directories(mini fileBrowser)
set(SOURCES
        mainwindow.ui
        mainwindow.cpp
		mainwindow.hpp
        main.cpp
        behavior/shortcuts.cpp
		behavior/actions.cpp
		behavior/appearance.cpp
        syntaxHighlighter/syntaxHighlighter.cpp
		syntaxHighlighter/syntaxHighlighter.hpp
        stylesheets.cpp
        configuration/configurator.cpp configuration/configurator.hpp appearance/themes.cpp appearance/themes.h)
add_executable(mini
        ${SOURCES}
        )

target_link_libraries(mini Qt5::Widgets)
