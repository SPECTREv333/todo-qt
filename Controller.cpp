//
// Created by leonardo on 28/07/24.
//

#include "TodoEditDialog.h"
#include "Controller.h"

void Controller::addTodo() {

    TodoEditDialog dialog(std::make_shared<Todo>());
    if(dialog.exec() == QDialog::Accepted) {
        todolist->addTodo(dialog.getTodo());
    }

}

void Controller::removeTodo(std::shared_ptr<Todo> todo) {
    todolist->removeTodo(todo);
}
