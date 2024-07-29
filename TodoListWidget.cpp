//
// Created by leonardo on 29/07/24.
//

#include <QGridLayout>
#include <QPushButton>
#include "TodoListWidget.h"
#include "TodoWidget.h"

TodoListWidget::~TodoListWidget() {
    todoList->removeObserver(this);
}

TodoListWidget::TodoListWidget(QWidget *parent, TodoList *todoList, Controller *controller) : QWidget(parent) {
    this->todoList = todoList;
    this->controller = controller;
    todoList->addObserver(this);

    auto *layout = new QGridLayout(this);
    listWidget = new QListWidget(this);
    layout->addWidget(listWidget, 0, 0, 1, 2);
    auto *addButton = new QPushButton("Add", this);
    layout->addWidget(addButton, 1, 0);
    auto *removeButton = new QPushButton("Remove", this);
    layout->addWidget(removeButton, 1, 1);

}

void TodoListWidget::update() {
    listWidget->clear();
    for (auto &todo : todoList->getTodos()) {
        auto *todoWidget = new TodoWidget(listWidget, &todo, controller);
        listWidget->addItem(todoWidget);

    }
}

void TodoListWidget::addTodo() {
    controller->addTodo();

}

void TodoListWidget::removeTodo() {
    TodoWidget* widget = dynamic_cast<TodoWidget *>(listWidget->selectedItems().first()); // TODO: handle multiple selection
    if (widget != nullptr) {
        controller->removeTodo(widget);
    }
}
