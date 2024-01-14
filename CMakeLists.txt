cmake_minimum_required(VERSION 3.5)

project(FreeThrowApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FreeThrowApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Player.h




        editplayers.h editplayers.cpp editplayers.ui
        viewstats.h viewstats.cpp viewstats.ui
        addplayer.h addplayer.cpp addplayer.ui
        team.h team.cpp
        startgame.h startgame.cpp startgame.ui
        points.h points.cpp points.ui
        stats.h stats.cpp stats.ui
        removeplayer.h removeplayer.cpp removeplayer.ui
        removeone.h removeone.cpp removeone.ui
        pointschoice.h pointschoice.cpp pointschoice.ui
        savedata.txt

        HomeTeam.h
        AbstractTeam.h
        savedata.qrc







    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FreeThrowApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FreeThrowApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FreeThrowApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FreeThrowApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.FreeThrowApp)
endif()
set_target_properties(FreeThrowApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS FreeThrowApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FreeThrowApp)
endif()
