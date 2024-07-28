//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODO_H
#define TODO_TODO_H


#include <string>
#include "Subject.h"

class Todo : public Subject {
public:

    const std::string &getName() const;

    void setName(const std::string &name);

    bool isDone() const;

    void setDone(bool done);


private:
    std::string name;
    bool done;

};


#endif //TODO_TODO_H
