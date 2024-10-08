cmake_minimum_required(VERSION 3.28)
project(todo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(SOURCES
        Todo.cpp
        Todo.h
        TodoList.cpp
        TodoList.h
        Observer.h
        Subject.h
        Controller.cpp
        Controller.h
        TodoEditDialog.cpp
        TodoEditDialog.h
        Serializable.h
        MainWindow.cpp
        MainWindow.h
        TodoTableView.h
        TodoTableView.cpp
        TodoListQAbstractTableModelAdapter.h
        TodoListQAbstractTableModelAdapter.cpp
)

# Application core (includes all classes + Qt)
add_library(core ${SOURCES})

target_link_libraries(core
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

# add main and link it against core
add_executable(todo main.cpp)

target_link_libraries(todo core)

# googletest
add_subdirectory(test)


