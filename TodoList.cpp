//
// Created by leonardo on 28/07/24.
//

#include <algorithm>
#include "TodoList.h"
#include <QDataStream>
#include <QIODevice>


void TodoList::addTodo(Todo todo) {
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
    for (auto observer: observers) {
        observer->update();
    }
}

void TodoList::removeTodo(Todo& todo) {
    todos.removeOne(todo);
    notify();
}


QByteArray TodoList::serialize() {
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    for (auto &todo: todos) {
        stream << todo.serialize();
    }
    return data;
}

void TodoList::deserialize(const QByteArray &data) {
    QDataStream stream(data);
    todos.clear();
    while (!stream.atEnd()) {
        QByteArray todoData;
        stream >> todoData;
        Todo todo;
        todo.deserialize(todoData);
        todos.push_back(todo);
    }
    notify();

}

const Todo& TodoList::getTodo(int i) {
    return todos[i];
}

int TodoList::size() {
    return todos.size();
}

int TodoList::doneCount() {
    int count = 0;
    for (auto todo: todos) {
        count += todo.isDone() ? 1 : 0;
    }
    return count;
}

int TodoList::notDoneCount() {
    return size() - doneCount();
}

void TodoList::removeTodo(int i) {
    todos.removeAt(i);
}

void TodoList::toggleDone(int i) {
    todos[i].setDone(!todos[i].isDone());
    notify();
}

void TodoList::setTodo(int i, const Todo &todo) {
    todos[i] = todo;
    notify();
}
