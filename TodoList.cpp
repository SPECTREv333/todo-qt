//
// Created by leonardo on 28/07/24.
//

#include <algorithm>
#include "TodoList.h"

const std::list<std::shared_ptr<Todo>> &TodoList::getTodos() const {
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
    observers.remove(observer);
}

void TodoList::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}

void TodoList::removeTodo(std::shared_ptr<Todo> todo) {
    todos.remove(todo);
    notify();
}

std::list<std::shared_ptr<Todo>> &TodoList::getTodos() {
    return todos;
}

