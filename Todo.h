//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODO_H
#define TODO_TODO_H


#include <string>
#include <list>
#include "Subject.h"

class Todo : public Subject {
public:
    Todo(std::string desc, bool done) : description(desc), done(done) {}

    const std::string &getDescription() const;

    void setDescription(const std::string &desc);

    bool isDone() const;

    void setDone(bool done);

    void addObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notify() override;


private:
    std::list<Observer *> observers;
    std::string description;
    bool done;

};


#endif //TODO_TODO_H
