//
// Created by leonardo on 28/07/24.
//

#include <QHBoxLayout>
#include "TodoWidget.h"

void TodoWidget::update() {
    label->setText(todo->getDescription().c_str());
    checkBox->setChecked(todo->isDone());
}

TodoWidget::TodoWidget(QListWidget *parent, Todo *todo, Controller *controller)
        : QListWidgetItem(parent), todo(todo), controller(controller) {

    todo->addObserver(this);
    layout = new QHBoxLayout(nullptr);
    checkBox = new QCheckBox(nullptr);
    checkBox->setChecked(todo->isDone());
    label = new QLabel(todo->getDescription().c_str(), nullptr);
    layout->addWidget(label);
    layout->addWidget(checkBox);
    connect(checkBox, &QCheckBox::stateChanged, this, &TodoWidget::todoChanged);

}

TodoWidget::~TodoWidget() {
    todo->removeObserver(this);

}

void TodoWidget::todoChanged() {
    controller->setDone(checkBox->isChecked());
}

Todo *TodoWidget::getTodo() const {
    return todo;
}

void TodoWidget::setTodo(Todo *todo) {
    TodoWidget::todo = todo;
}
