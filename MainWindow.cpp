//
// Created by leonardo on 31/07/24.
//

#include "MainWindow.h"
#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(TodoList *todolist, Controller *controller, QWidget *parent) {
    this->controller = controller;

    todoListWidget = new TodoListWidget(this, todolist, controller);
    setCentralWidget(todoListWidget);

    setGeometry(100, 100, 800, 600);

    auto fileMenu = menuBar()->addMenu("File");
    auto saveAction = fileMenu->addAction("Save");
    auto saveAsAction = fileMenu->addAction("Save As");
    auto loadAction = fileMenu->addAction("Load");
    auto exitAction = fileMenu->addAction("Exit");

    saveAction->setShortcut(QKeySequence::Save);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    loadAction->setShortcut(QKeySequence::Open);
    exitAction->setShortcut(QKeySequence::Quit);

    connect(saveAction, &QAction::triggered, this, &MainWindow::save);
    connect(loadAction, &QAction::triggered, this, &MainWindow::load);
    connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveAs);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    auto editMenu = menuBar()->addMenu("Edit");
    auto addTodoAction = editMenu->addAction("Add Todo");

    addTodoAction->setShortcut(QKeySequence::New);

    connect(addTodoAction, &QAction::triggered, this, &MainWindow::addTodo);

}

void MainWindow::addTodo() {
    controller->addTodo();
}

void MainWindow::save() {
    if (currentPath.isEmpty()) {
        saveAs();
    } else {
        controller->saveToFile(currentPath);
    }
}


void MainWindow::saveAs() {
    auto path = QFileDialog::getSaveFileName(this, "Save Todo List", currentPath, "Todo List (*.todo)");
    if (!path.isEmpty()) {
        if (!path.endsWith(".todo")) {
            path.append(".todo");
        }
        controller->saveToFile(path);
        currentPath = path;
    }
}

void MainWindow::load() {
    auto path = QFileDialog::getOpenFileName(this, "Load Todo List", currentPath, "Todo List (*.todo)");
    if (!path.isEmpty()) {
        controller->loadFromFile(path);
        currentPath = path;
    }
}

