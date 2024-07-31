#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "TodoList.h"
#include "Controller.h"
#include "TodoWidget.h"
#include "TodoListWidget.h"
#include "Todo.h"
#include <memory>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TodoList todoList;
    Controller controller(&todoList);
    TodoListWidget todoListWidget(nullptr, &todoList, &controller);



    todoListWidget.show();

    return QApplication::exec();
}
