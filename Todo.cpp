//
// Created by leonardo on 28/07/24.
//

#include "Todo.h"

const QString & Todo::getDescription() const {
    return description;
}

void Todo::setDescription(const QString &desc) {
    Todo::description = desc;
    notify();
}

bool Todo::isDone() const {
    return done;
}

void Todo::setDone(bool done) {
    Todo::done = done;
    notify();
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

bool Todo::operator==(const Todo &rhs) const {
    return description == rhs.description && done == rhs.done;
}

bool Todo::operator!=(const Todo &rhs) const {
    return !(rhs == *this);
}

const QString & Todo::getTitle() const {
    return title;
}

void Todo::setTitle(const QString &title) {
    Todo::title = title;
    notify();
}
