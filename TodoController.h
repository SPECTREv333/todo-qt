//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOCONTROLLER_H
#define TODO_TODOCONTROLLER_H


#include "Todo.h"

class TodoController {
public:

    explicit TodoController(Todo *todo) : todo(todo) {};

    void setDescription(const std::string &desc);

    void setDone(bool done);

private:
    Todo *todo;

};


#endif //TODO_TODOCONTROLLER_H
