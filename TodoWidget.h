//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOWIDGET_H
#define TODO_TODOWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include "Observer.h"
#include "Todo.h"
#include "TodoController.h"

class TodoWidget : public QWidget, public Observer {
Q_OBJECT

public:

    TodoWidget(QWidget *parent, Todo *todo, TodoController *controller);
    ~TodoWidget() override;

    void update() override;

public slots:
    void todoChanged();

private:
    Todo *todo;
    TodoController *controller;
    QLabel *label;
    QCheckBox *checkBox;

};


#endif //TODO_TODOWIDGET_H
