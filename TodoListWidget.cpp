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
    TodoListWidget::todoList = todoList;
    TodoListWidget::controller = controller;
    todoList->addObserver(this);

    auto *layout = new QGridLayout(this);
    setLayout(layout);

    auto *scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Window);
    scrollArea->setFrameShadow(QFrame::Plain);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setWidgetResizable(true);

    scrollAreaContent = new QWidget(this);
    scrollAreaContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollAreaContent->setLayout(new QVBoxLayout(scrollAreaContent));
    scrollAreaContent->layout()->setAlignment(Qt::AlignTop);
    scrollArea->setWidget(scrollAreaContent);

    layout->addWidget(scrollArea, 0, 0);

}

void TodoListWidget::update() {
    for (auto todoWidget : todoWidgets) {
        delete todoWidget;
    }
    todoWidgets.clear();

    for (int i = 0; i<todoList->size(); i++) {
        auto todo = todoList->getTodo(i);
        auto *todoWidget = new TodoWidget(scrollAreaContent, todo, controller);
        todoWidgets.push_back(todoWidget);
        scrollAreaContent->layout()->addWidget(todoWidget);
    }
}

