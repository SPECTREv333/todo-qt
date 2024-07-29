//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_CONTROLLER_H
#define TODO_CONTROLLER_H


#include "Todo.h"
#include "TodoList.h"
#include "TodoWidget.h"


class Controller {
public:

    explicit Controller(TodoList *todolist) : todolist(todolist) {};

    void setDescription(Todo &todo, const std::string &desc);

    void setDone(Todo &todo, bool done);

    void addTodo();

    void removeTodo(TodoWidget *pWidget);

private:
    TodoList *todolist;

};


#endif //TODO_CONTROLLER_H
