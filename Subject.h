//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_SUBJECT_H
#define TODO_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer *observer) = 0;

    virtual void removeObserver(Observer *observer) = 0;

    virtual void notify() = 0;

};


#endif //TODO_SUBJECT_H
