//
// Created by leonardo on 31/07/24.
//

#ifndef TODO_MAINWINDOW_H
#define TODO_MAINWINDOW_H

#include "Controller.h"
#include "Observer.h"
#include <QMainWindow>
#include "TodoListWidget.h"
#include "TodoList.h"

class MainWindow : public QMainWindow, Observer {
    Q_OBJECT
public:
    explicit MainWindow(TodoList *todolist, Controller *controller, QWidget *parent = nullptr);

    ~MainWindow() override;

    void update() override;

public slots:
    void save();
    void saveAs();
    void load();
    void addTodo();

private:
    Controller *controller;
    TodoListWidget *todoListWidget;
    QString currentPath;
    TodoList *todoList;

};


#endif //TODO_MAINWINDOW_H
