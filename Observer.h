//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_OBSERVER_H
#define TODO_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;

};


#endif //TODO_OBSERVER_H
