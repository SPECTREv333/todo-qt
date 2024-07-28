//
// Created by leonardo on 28/07/24.
//

#include <QHBoxLayout>
#include "TodoWidget.h"

void TodoWidget::update() {
    label->setText(todo->getDescription().c_str());
    checkBox->setChecked(todo->isDone());
}

TodoWidget::TodoWidget(QWidget *parent, Todo *todo, TodoController *controller)
        : QWidget(parent), todo(todo), controller(controller) {

    todo->addObserver(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    checkBox = new QCheckBox(this);
    checkBox->setChecked(todo->isDone());
    label = new QLabel(todo->getDescription().c_str(), this);
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
