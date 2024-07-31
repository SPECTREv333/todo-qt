//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOLIST_H
#define TODO_TODOLIST_H


#include <vector>
#include <memory>
#include "Todo.h"
#include "Serializable.h"

class TodoList : public Subject, public Serializable {
public:

    void addTodo(std::shared_ptr<Todo> todo);

    void removeTodo(std::shared_ptr<Todo> todo);

    const QList<std::shared_ptr<Todo>> &getTodos() const;

    QList<std::shared_ptr<Todo>> &getTodos();

    void addObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notify() override;

    QByteArray serialize() override;

    void deserialize(const QByteArray& data) override;

private:
    QList<Observer *> observers;
    QList<std::shared_ptr<Todo>> todos;

};


#endif //TODO_TODOLIST_H
