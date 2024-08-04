//
// Created by leonardo on 28/07/24.
//

#include <algorithm>
#include "TodoList.h"
#include <QDataStream>
#include <QIODevice>

const QList<std::shared_ptr<Todo>> &TodoList::getTodos() const {
    return todos;
}

void TodoList::addTodo(std::shared_ptr<Todo> todo) {
    todos.push_back(todo);
    notify();
}

void TodoList::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void TodoList::removeObserver(Observer *observer) {
    observers.removeOne(observer);
}

void TodoList::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}

void TodoList::removeTodo(std::shared_ptr<Todo> todo) {
    todos.removeOne(todo);
    notify();
}

QList<std::shared_ptr<Todo>> &TodoList::getTodos() {
    return todos;
}

QByteArray TodoList::serialize() {
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    for (const auto &todo : todos) {
        stream << todo->serialize();
    }
    return data;
}

void TodoList::deserialize(const QByteArray &data) {
    QDataStream stream(data);
    todos.clear();
    while (!stream.atEnd()) {
        QByteArray todoData;
        stream >> todoData;
        auto todo = std::make_shared<Todo>();
        todo->deserialize(todoData);
        todos.push_back(todo);
    }
    notify();

}

