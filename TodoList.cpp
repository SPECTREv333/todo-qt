//
// Created by leonardo on 28/07/24.
//

#include "TodoList.h"

const std::vector<Todo> &TodoList::getTodos() const {
    return todos;
}

void TodoList::addTodo(const Todo& todo) {
    todos.push_back(todo);
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
