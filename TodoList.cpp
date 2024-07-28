//
// Created by leonardo on 28/07/24.
//

#include "TodoList.h"

const std::vector<Todo> &TodoList::getTodos() const {
    return todos;
}

void TodoList::addTodo(Todo todo) {
    todos.push_back(todo);
}
