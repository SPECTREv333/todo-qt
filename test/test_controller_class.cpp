//
// Created by leonardo on 01/08/24.
//

#include <gtest/gtest.h>
#include <QFile>
#include "../Todo.h"
#include "../Controller.h"
#include <memory>

class ControllerTests : public ::testing::Test {
protected:
    TodoList todoList;

    void SetUp() override {
        auto todo1 = std::make_shared<Todo>("Title1", "Description1", false);
        auto todo2 = std::make_shared<Todo>("Title2", "Description2", true);

        todoList.addTodo(todo1);
        todoList.addTodo(todo2);
    }

    void TearDown() override {
        QFile::remove("test.todo");
    }
};

TEST_F(ControllerTests, save_load_file) {
    Controller controller(&todoList);

    controller.saveToFile("test.todo");

    TodoList newTodoList;
    Controller load_controller(&newTodoList);
    load_controller.loadFromFile("test.todo");

    EXPECT_EQ(todoList.getTodos().size(), newTodoList.getTodos().size());
    EXPECT_EQ(*(todoList.getTodos()[0]), *(newTodoList.getTodos()[0]));
    EXPECT_EQ(*(todoList.getTodos()[1]), *(newTodoList.getTodos()[1]));
}