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

    void showCreationDialog();

    void addTodo(std::shared_ptr<Todo> todo);

    void removeTodo(std::shared_ptr<Todo> todo);

    void toggleTodo(std::shared_ptr<Todo> todo);

    void showEditDialog(std::shared_ptr<Todo> todo);

    bool saveToFile(const QString &path);

    bool loadFromFile(const QString &path);

private:
    TodoList *todolist;


};


#endif //TODO_CONTROLLER_H
