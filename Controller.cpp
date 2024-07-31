//
// Created by leonardo on 28/07/24.
//

#include "TodoEditDialog.h"
#include "Controller.h"
#include <QFile>

void Controller::addTodo() {

    TodoEditDialog dialog(std::make_shared<Todo>());
    if(dialog.exec() == QDialog::Accepted) {
        todolist->addTodo(dialog.getTodo());
    }

}

void Controller::removeTodo(std::shared_ptr<Todo> todo) {
    todolist->removeTodo(todo);
}

void Controller::saveToFile(const QString &path) {
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(todolist->serialize());
        file.close();
    }
}

void Controller::loadFromFile(const QString &path) {
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        todolist->deserialize(file.readAll());
        file.close();
    }
}
