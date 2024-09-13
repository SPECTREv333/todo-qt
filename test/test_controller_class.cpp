//
// Created by leonardo on 01/08/24.
//

#include <gtest/gtest.h>
#include <QFile>
#include "../Todo.h"
#include "../Controller.h"
#include <QDateTime>
#include <memory>

class ControllerTests : public ::testing::Test {
protected:
    TodoList todoList;

    void SetUp() override {
        auto todo1 = std::make_shared<Todo>("Title1", "Description1", false, QDateTime(QDate(), QTime()));
        auto todo2 = std::make_shared<Todo>("Title2", "Description2", true, QDateTime(QDate(), QTime()));

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

    EXPECT_EQ(todoList.size(), newTodoList.size());
    EXPECT_EQ(*(todoList.getTodo(0)), *(newTodoList.getTodo(0)));
    EXPECT_EQ(*(todoList.getTodo(1)), *(newTodoList.getTodo(1)));
}

TEST_F(ControllerTests, add_todo) {
    Controller controller(&todoList);
    auto newTodo = std::make_shared<Todo>("New Title", "New Description", false, QDateTime(QDate(), QTime()));
    controller.addTodo(newTodo);

    EXPECT_EQ(todoList.size(), 3);
    EXPECT_EQ(*(todoList.getTodo(2)), *newTodo);
}

TEST_F(ControllerTests, remove_todo) {
    Controller controller(&todoList);
    auto todoToRemove = todoList.getTodo(0);
    controller.removeTodo(todoToRemove);

    EXPECT_EQ(todoList.size(), 1);
    EXPECT_NE(*(todoList.getTodo(0)), *todoToRemove);
}