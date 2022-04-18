cmake_minimum_required(VERSION 3.21)
project(BarybiansX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(QT NAMES Qt6 COMPONENTS Widgets Network REQUIRED)
AUX_SOURCE_DIRECTORY(base/, BASE_SOURCES)
AUX_SOURCE_DIRECTORY(cwidgets/, CWIDGETS_SOURCES)
AUX_SOURCE_DIRECTORY(fragmentts/, FRAGMENTTS_SOURCES)
AUX_SOURCE_DIRECTORY(fragmentts/, FRAGMENTS_SOURCES)
add_executable(BarybiansX
        ${CMAKE_SOURCE_DIR}
        main.cpp
        ${BASE_SOURCES}
        ${CWIDGETS_SOURCES}
        ${FRAGMENTTS_SOURCES}
        base/basefragmentfactory.h
        base/basefragmentfactory.cpp
        cwidgets/slidingstackedwidget.cpp
        ${FRAGMENTS_SOURCES}
        mainwindow.cpp
        mainwindow.h
        base/data/data.cpp
        base/data/data.h
        cwidgets/implfragmentfactory.cpp
        fragmentts/loginfragment.cpp
        fragmentts/loginfragment.h
        base/basefragment.cpp
        base/basefragment.h
        base/utils/webconnector.cpp
        base/utils/webconnectorx.cpp
        cwidgets/slidingstackedwidget.cpp
        cwidgets/slidingstackedwidget.h
        fragmentts/splashfragment.cpp
        fragmentts/splashfragment.h
        fragmentts/userpagefragment.cpp
        cwidgets/cardview.cpp
        cwidgets/addition/cardwidget.cpp
        cwidgets/addition/menuheaderwidget.cpp
        base/router.h
        base/router.cpp
        base/utils/requestx.cpp
        base/basemodel.cpp
        base/data/data.cpp
        res.qrc
        fragmentts/dialogfragment.cpp fragmentts/dialogfragment.h cwidgets/addition/EditorWindow.cpp cwidgets/addition/EditorWindow.h fragmentts/editorsplashfragment.cpp fragmentts/editorsplashfragment.h meditorsplash.cpp meditorsplash.h fragmentts/feedfragment.cpp fragmentts/feedfragment.h)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Network REQUIRED)
find_package(Qt6WebSockets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS SvgWidgets)
target_link_libraries(BarybiansX PRIVATE Qt6::SvgWidgets)
target_link_libraries(BarybiansX PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(BarybiansX PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(BarybiansX PRIVATE Qt${QT_VERSION_MAJOR}::Network)
