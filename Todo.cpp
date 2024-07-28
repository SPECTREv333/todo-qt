//
// Created by leonardo on 28/07/24.
//

#include "Todo.h"

const std::string &Todo::getDescription() const {
    return description;
}

void Todo::setDescription(const std::string &desc) {
    Todo::description = desc;
}

bool Todo::isDone() const {
    return done;
}

void Todo::setDone(bool done) {
    Todo::done = done;
}

void Todo::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void Todo::removeObserver(Observer *observer) {
    observers.remove(observer);
}

void Todo::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}
