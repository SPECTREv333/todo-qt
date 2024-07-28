#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QMainWindow>
#include "TodoList.h"
#include "TodoController.h"
#include "TodoWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Todo todo1("Buy milk", false);
    TodoController controller(&todo1);
    TodoWidget widget(nullptr, &todo1, &controller);
    widget.show();



    return QApplication::exec();



}
