//
// Created by leonardo on 28/07/24.
//

#include <algorithm>
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

std::vector<Todo> &TodoList::getTodos() {
    return todos;
}

void TodoList::removeTodo(Todo &todo) {
    auto iter = std::find(todos.begin(), todos.end(), todo);
    if (iter != todos.end()) {
        todos.erase(iter);
    }
}
