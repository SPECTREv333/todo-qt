//
// Created by leonardo on 28/07/24.
//

#include "TodoEditDialog.h"
#include "Controller.h"
#include <QFile>
#include <utility>

void Controller::showCreationDialog() {
    Todo newTodo; // TODO: refactor gui classes to build ui in a separate class
    TodoEditDialog dialog(newTodo);
    if(dialog.exec() == QDialog::Accepted) {
        addTodo(dialog.getTodo());
    }
}

void Controller::addTodo(Todo& todo) {
    todolist->addTodo(todo);
}

void Controller::removeTodo(int i) {
    todolist->removeTodo(i); // avoid copy
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

void Controller::showEditDialog(int i) {
    Todo newTodo(todolist->getTodo(i));
    TodoEditDialog dialog(newTodo);
    dialog.exec();
    todolist->setTodo(i, newTodo);
}

void Controller::toggleTodo(int i) {
    todolist->toggleDone(i);
}
