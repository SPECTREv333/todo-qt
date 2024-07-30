//
// Created by leonardo on 29/07/24.
//

#ifndef TODO_TODOLISTWIDGET_H
#define TODO_TODOLISTWIDGET_H


#include <QWidget>
#include <QListWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "TodoWidget.h"
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

private:
    TodoList* todoList;
    Controller *controller;
    QWidget *scrollAreaContent;
    std::list<TodoWidget*> todoWidgets;



};


#endif //TODO_TODOLISTWIDGET_H
