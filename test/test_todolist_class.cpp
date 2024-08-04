//
// Created by leonardo on 01/08/24.
//

#include <gtest/gtest.h>
#include "../Todo.h"
#include "../TodoList.h"

TEST(TodoListTests, add_remove_todo) {
    TodoList todoList;
    auto todo1 = std::make_shared<Todo>("Title1", "Description1", false);
    auto todo2 = std::make_shared<Todo>("Title2", "Description2", true);

    todoList.addTodo(todo1);
    todoList.addTodo(todo2);

    EXPECT_EQ(todoList.getTodos().size(), 2);

    todoList.removeTodo(todo1);
    EXPECT_EQ(todoList.getTodos().size(), 1);

    todoList.removeTodo(todo2);
    EXPECT_EQ(todoList.getTodos().size(), 0);
}

TEST(TodoListTests, serialize_deserialize) {
    TodoList originalList;
    originalList.addTodo(std::make_shared<Todo>("Title1", "Description1", false));
    originalList.addTodo(std::make_shared<Todo>("Title2", "Description2", true));

    QByteArray data = originalList.serialize();

    TodoList newList;
    newList.deserialize(data);

    EXPECT_EQ(originalList.getTodos().size(), newList.getTodos().size());
    EXPECT_EQ(*(originalList.getTodos()[0]), *(newList.getTodos()[0]));
    EXPECT_EQ(*(originalList.getTodos()[1]), *(newList.getTodos()[1]));
}

TEST(TodoListTests, double_deserialize) {
    TodoList originalList;
    originalList.addTodo(std::make_shared<Todo>("Title1", "Description1", false));
    originalList.addTodo(std::make_shared<Todo>("Title2", "Description2", true));

    QByteArray data = originalList.serialize();

    TodoList newList;
    newList.deserialize(data);
    newList.deserialize(data);

    EXPECT_EQ(originalList.getTodos().size(), newList.getTodos().size());
    EXPECT_EQ(*(originalList.getTodos()[0]), *(newList.getTodos()[0]));
    EXPECT_EQ(*(originalList.getTodos()[1]), *(newList.getTodos()[1]));
}