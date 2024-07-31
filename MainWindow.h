//
// Created by leonardo on 31/07/24.
//

#ifndef TODO_MAINWINDOW_H
#define TODO_MAINWINDOW_H

#include "Controller.h"
#include <QMainWindow>
#include "TodoListWidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(TodoList *todolist, Controller *controller, QWidget *parent = nullptr);

public slots:
    void save();
    void saveAs();
    void load();
    void addTodo();

private:
    Controller *controller;
    TodoListWidget *todoListWidget;
    QString currentPath;

};


#endif //TODO_MAINWINDOW_H
