//
// Created by leonardo on 29/07/24.
//

#ifndef TODO_TODOLISTWIDGET_H
#define TODO_TODOLISTWIDGET_H


#include <QWidget>
#include <QListWidget>
#include "Observer.h"
#include "TodoList.h"
#include "Controller.h"

class TodoListWidget : public QWidget, public Observer {
    Q_OBJECT
public:

    explicit TodoListWidget(QWidget *parent, TodoList *todoList, Controller *controller);
    ~TodoListWidget() override;

    void update() override;

public slots:

    void addTodo();

    void removeTodo();


private:
    TodoList* todoList;
    QListWidget *listWidget;
    Controller *controller;



};


#endif //TODO_TODOLISTWIDGET_H
