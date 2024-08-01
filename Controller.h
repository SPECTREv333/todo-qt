//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_CONTROLLER_H
#define TODO_CONTROLLER_H


#include "Todo.h"
#include "TodoList.h"

class Controller {
public:

    explicit Controller(TodoList *todolist) : todolist(todolist) {};

    void addTodo();

    void removeTodo(std::shared_ptr<Todo> todo);

    void editTodo(std::shared_ptr<Todo> todo);

    void saveToFile(const QString &path);

    void loadFromFile(const QString &path);

private:
    TodoList *todolist;

};


#endif //TODO_CONTROLLER_H
