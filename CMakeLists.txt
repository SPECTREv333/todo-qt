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

add_executable(todo main.cpp
        Todo.cpp
        Todo.h
        TodoList.cpp
        TodoList.h
        Observer.h
        Subject.h
        TodoWidget.cpp
        TodoWidget.h
        Controller.cpp
        Controller.h
        TodoListWidget.cpp
        TodoListWidget.h
        TodoEditDialog.cpp
        TodoEditDialog.h
        Serializable.h
        MainWindow.cpp
        MainWindow.h
)
target_link_libraries(todo
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

