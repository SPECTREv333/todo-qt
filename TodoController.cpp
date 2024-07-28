//
// Created by leonardo on 28/07/24.
//

#include "TodoController.h"


void TodoController::setDone(bool done) {
    todo->setDone(done);
}

void TodoController::setDescription(const std::string &desc) {
    todo->setDescription(desc);
}
