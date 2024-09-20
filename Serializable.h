//
// Created by leonardo on 31/07/24.
//

#ifndef TODO_SERIALIZABLE_H
#define TODO_SERIALIZABLE_H

#include <QByteArray>

class Serializable {
public:
    virtual ~Serializable() = default;
    virtual QByteArray serialize() const = 0;
    virtual void deserialize(const QByteArray& data) = 0;
};


#endif //TODO_SERIALIZABLE_H
