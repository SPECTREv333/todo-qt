#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "TodoList.h"

int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();

    TodoList list;

    list.addTodo({"Buy milk", false});
    list.addTodo({"Buy bread", true});
    list.addTodo({"Buy butter", false});

    for (const auto& todo : list.getTodos()) {
        std::cout << (todo.isDone() ? "[x]" : "[ ]") << todo.getDescription() << std::endl;
    }


    return 0;
}
