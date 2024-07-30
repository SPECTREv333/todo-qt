//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOLIST_H
#define TODO_TODOLIST_H


#include <vector>
#include <memory>
#include "Todo.h"

class TodoList : public Subject{
public:

    void addTodo(std::shared_ptr<Todo> todo);

    void removeTodo(std::shared_ptr<Todo> todo);

    const std::list<std::shared_ptr<Todo>> &getTodos() const;

    std::list<std::shared_ptr<Todo>> &getTodos();

    void addObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notify() override;

private:
    std::list<Observer *> observers;
    std::list<std::shared_ptr<Todo>> todos;

};


#endif //TODO_TODOLIST_H
