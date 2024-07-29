//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOWIDGET_H
#define TODO_TODOWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QListWidgetItem>
#include "Observer.h"
#include "Todo.h"
#include "Controller.h"

class TodoWidget : public QListWidgetItem, public Observer {
Q_OBJECT

public:

    TodoWidget(QListWidget *parent, Todo *todo, Controller *controller);
    ~TodoWidget() override;

    Todo *getTodo() const;

    void setTodo(Todo *todo);

    void update() override;

public slots:
    void todoChanged();

private:
    Todo *todo;
    Controller *controller;
    QLabel *label;
    QCheckBox *checkBox;
    QHBoxLayout *layout;

};


#endif //TODO_TODOWIDGET_H
