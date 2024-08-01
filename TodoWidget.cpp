//
// Created by leonardo on 28/07/24.
//

#include <QHBoxLayout>
#include <QPushButton>
#include "TodoWidget.h"

TodoWidget::TodoWidget(QWidget *parent, std::shared_ptr<Todo> todo, Controller *controller)
        : QWidget(parent), todo(std::move(todo)), controller(controller) {

    TodoWidget::todo->addObserver(this);
    setLayout(new QHBoxLayout(this));

    auto* tickableLabel = new QWidget(this);
    auto* tickableLabelLayout = new QHBoxLayout(tickableLabel);
    tickableLabelLayout->setAlignment(Qt::AlignLeft);
    checkBox = new QCheckBox(this);
    checkBox->setChecked(TodoWidget::todo->isDone());
    label = new QLabel(TodoWidget::todo->getTitle(), this);
    tickableLabelLayout->addWidget(checkBox);
    tickableLabelLayout->addWidget(label);

    auto* buttonBar = new QWidget(this);
    auto* buttonBarLayout = new QHBoxLayout(buttonBar);
    buttonBarLayout->setAlignment(Qt::AlignRight);

    auto *deleteButton = new QPushButton("Delete", this);
    buttonBarLayout->addWidget(deleteButton);

    auto *editButton = new QPushButton("Edit", this);
    buttonBarLayout->addWidget(editButton);


    layout()->addWidget(tickableLabel);
    layout()->addWidget(buttonBar);
    layout()->setContentsMargins(0, 0, 0, 0);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    connect(checkBox, &QCheckBox::stateChanged, this, &TodoWidget::todoChanged);
    connect(deleteButton, &QPushButton::clicked, this, &TodoWidget::removeTodo);
    connect(editButton, &QPushButton::clicked, this, &TodoWidget::editTodo);

}

TodoWidget::~TodoWidget() {
    todo->removeObserver(this);
}

void TodoWidget::todoChanged() {
    todo->setDone(checkBox->isChecked());
}

std::shared_ptr<Todo> TodoWidget::getTodo() const {
    return todo;
}

void TodoWidget::setTodo(std::shared_ptr<Todo> todo) {
    TodoWidget::todo = std::move(todo);
}

void TodoWidget::removeTodo() {
    controller->removeTodo(todo);
}

void TodoWidget::update() {
    label->setText(todo->getTitle());
    checkBox->setChecked(todo->isDone());
}

void TodoWidget::editTodo() {
    controller->editTodo(todo);
}

