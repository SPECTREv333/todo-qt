//
// Created by leonardo on 28/07/24.
//

#include "Todo.h"

const std::string &Todo::getName() const {
    return name;
}

void Todo::setName(const std::string &name) {
    Todo::name = name;
}

bool Todo::isDone() const {
    return done;
}

void Todo::setDone(bool done) {
    Todo::done = done;
}
