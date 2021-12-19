cmake_minimum_required(VERSION 3.5)

project(my_love_project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(MAIN_FILES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

set(CAT_FORM_FILES
        catform.cpp
        catform.h
        catform.ui
)

set(REG_FORM_FILES
        regform.cpp
        regform.h
        regform.ui
)

set(PLAN_FILES
        planwindow.cpp
        planwindow.h
        planwindow.ui
)

set(SET_FORM_FILES
        settingsform.cpp
        settingsform.h
        settingsform.ui
)

set(SET_CREATE_NEW_TASK
        create_new_task.cpp
        create_new_task.h
        create_new_task.ui
)

set(SET_EDIT_TASK
        edittask.cpp
        edittask.h
        edittask.ui
)

set(PROJECT_SOURCES
      ${MAIN_FILES}
      ${CAT_FORM_FILES}
      ${REG_FORM_FILES}
      ${PLAN_FILES}
      ${SET_FORM_FILES}
      ${SET_CREATE_NEW_TASK}
      ${SET_EDIT_TASK}
)

set(RESOURCES
        resources.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(my_love_project
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(my_love_project SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(my_love_project
            ${PROJECT_SOURCES} ${RESOURCES}
        )
    endif()
endif()

target_link_libraries(my_love_project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
