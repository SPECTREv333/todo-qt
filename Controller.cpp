//
// Created by leonardo on 28/07/24.
//

#include "Controller.h"


void Controller::setDescription(Todo &todo, const std::string &desc) {
    todo.setDescription(desc);
}

void Controller::setDone(Todo &todo, bool done) {
    todo.setDone(done);
}

void Controller::addTodo() {

}

void Controller::removeTodo(TodoWidget *pWidget) {

}
