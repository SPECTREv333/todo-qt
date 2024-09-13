//
// Created by leonardo on 28/07/24.
//

#include "TodoEditDialog.h"
#include "Controller.h"
#include <QFile>
#include <utility>

void Controller::showCreationDialog() {
    TodoEditDialog dialog(std::make_shared<Todo>());
    if(dialog.exec() == QDialog::Accepted) {
        addTodo(dialog.getTodo());
    }
}

void Controller::addTodo(std::shared_ptr<Todo> todo) {
    todolist->addTodo(todo);
}

void Controller::removeTodo(std::shared_ptr<Todo> todo) {
    todolist->removeTodo(std::move(todo)); // avoid copy
}

bool Controller::saveToFile(const QString &path) {
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(todolist->serialize());
        file.close();
        return file.error() == QFileDevice::NoError;
    }
    return false;
}

bool Controller::loadFromFile(const QString &path) {
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        todolist->deserialize(file.readAll());
        file.close();
        return file.error() == QFileDevice::NoError;
    }
    return false;
}

void Controller::showEditDialog(std::shared_ptr<Todo> todo) {
    TodoEditDialog dialog(std::move(todo)); // avoid copy
    dialog.exec();
}

void Controller::toggleTodo(std::shared_ptr<Todo> todo) {
    todo->setDone(!todo->isDone());
}
