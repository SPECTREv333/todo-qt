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

    void addTodo(Todo todo);

    void removeTodo(Todo& todo);

    void removeTodo(int i);

    const Todo& getTodo(int i);

    void setTodo(int i, const Todo& todo);

    void toggleDone(int i);

    int size();

    int notDoneCount();

    int doneCount();

    void addObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notify() override;

    QByteArray serialize() override;

    void deserialize(const QByteArray& data) override;

private:
    QList<Observer *> observers;
    QList<Todo> todos;

};


#endif //TODO_TODOLIST_H
