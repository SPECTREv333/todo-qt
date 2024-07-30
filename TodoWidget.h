//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODOWIDGET_H
#define TODO_TODOWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QScrollArea>
#include "Observer.h"
#include "Todo.h"
#include "Controller.h"

class TodoWidget : public QWidget, public Observer {
Q_OBJECT

public:
    explicit TodoWidget(QWidget *parent, std::shared_ptr<Todo> todo, Controller *controller);
    ~TodoWidget() override;

    std::shared_ptr<Todo> getTodo() const;
    void setTodo(std::shared_ptr<Todo> todo);
    void update() override;

public slots:
    void todoChanged();
    void removeTodo();
    void editTodo();

private:
    std::shared_ptr<Todo> todo;
    Controller *controller;
    QLabel *label;
    QCheckBox *checkBox;
};


#endif //TODO_TODOWIDGET_H
