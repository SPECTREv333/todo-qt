//
// Created by leonardo on 31/07/24.
//

#include "MainWindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QStatusBar>
#include "TodoListQAbstractTableModelAdapter.h"

MainWindow::MainWindow(TodoList *todolist, Controller *controller, QWidget *parent) {
    MainWindow::controller = controller;
    MainWindow::todoList = todolist;
    MainWindow::todoList->addObserver(this);

    setStatusBar(new QStatusBar(this));
    statusBar()->showMessage("Try creating a new todo (see global menu)");

    tableView = new TodoTableView(this, todolist, controller);
    setCentralWidget(tableView);

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
    controller->showCreationDialog();
}

void MainWindow::save() {
    if (currentPath.isEmpty()) {
        saveAs();
    } else {
        if (controller->saveToFile(currentPath))
            statusBar()->showMessage("Saved.", 1000);
    }
}


void MainWindow::saveAs() {
    auto path = QFileDialog::getSaveFileName(this, "Save Todo List", currentPath, "Todo List (*.todo)");
    if (path.isEmpty()) return;
    if (!path.endsWith(".todo")) {
        path.append(".todo");
    }
    if (controller->saveToFile(path)) {
        statusBar()->showMessage("Saved.", 1000);
        currentPath = path;
    } else {
        statusBar()->showMessage("Error saving file!");
    }
}

void MainWindow::load() {
    auto path = QFileDialog::getOpenFileName(this, "Load Todo List", currentPath, "Todo List (*.todo)");
    if (path.isEmpty()) return;
    if (controller->loadFromFile(path)){
        statusBar()->showMessage("Loaded successfully!", 1000);
        currentPath = path;
    } else {
        statusBar()->showMessage("Error loading file!");
    }

}

void MainWindow::update() {
    statusBar()->showMessage(QString("Todos: %1").arg(todoList->size()), 1000);
}

MainWindow::~MainWindow() {
    todoList->removeObserver(this);
}

