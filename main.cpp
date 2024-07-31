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
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TodoList todoList;
    Controller controller(&todoList);
    MainWindow mainWindow(&todoList, &controller);
    mainWindow.show();


    return QApplication::exec();
}
