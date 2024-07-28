//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOLIST_H
#define TODO_TODOLIST_H


#include <vector>
#include "Todo.h"

class TodoList : public Subject{
public:

    void addTodo(const Todo& todo);

    const std::vector <Todo> &getTodos() const;

    void addObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notify() override;

private:
    std::list<Observer *> observers;
    std::vector<Todo> todos;

};


#endif //TODO_TODOLIST_H
