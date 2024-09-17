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

    void addTodo(Todo& todo);

    void removeTodo(int i);

    void toggleTodo(int i);

    void showEditDialog(int i);

    bool saveToFile(const QString &path);

    bool loadFromFile(const QString &path);

private:
    TodoList *todolist;


};


#endif //TODO_CONTROLLER_H
