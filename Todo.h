//
// Created by leonardo on 28/07/24.
//

#ifndef TODO_TODO_H
#define TODO_TODO_H


#include <string>
#include <QList>
#include <qstring.h>
#include "Subject.h"
#include "Serializable.h"

class Todo : public Subject, public Serializable {
public:
    Todo() = default;

    Todo(const Todo &todo) : description(todo.description), done(todo.done) {}

    Todo(const QString &title, const QString &desc, bool done) : title(title), description(desc), done(done) {}

    const QString & getTitle() const;

    void setTitle(const QString &title);

    const QString & getDescription() const;

    void setDescription(const QString &desc);

    bool isDone() const;

    void setDone(bool done);

    void addObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notify() override;

    QByteArray serialize() override;

    void deserialize(const QByteArray& data) override;

    bool operator==(const Todo &rhs) const;

    bool operator!=(const Todo &rhs) const;


private:
    QList<Observer *> observers;
    QString title;
    QString description;
    bool done = false;

};


#endif //TODO_TODO_H
