//
// Created by leonardo on 13/09/24.
//

#ifndef TODO_TODOTABLEVIEW_H
#define TODO_TODOTABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include "Observer.h"
#include "TodoList.h"
#include "Controller.h"
#include "TodoListQAbstractTableModelAdapter.h"

class TodoTableView : public QWidget, Observer {
Q_OBJECT

public:
    TodoTableView(QWidget *parent, TodoList *todoList, Controller *controller);
    ~TodoTableView();
    void update();

private slots:
    void showContextMenu(const QPoint &pos);
    void removeTodo();
    void editTodo();
    void toggleTodo();

private:
    TodoList *todoList;
    Controller *controller;
    QTableView *tableView;
    TodoListQAbstractTableModelAdapter *adapter;
    QMenu *contextMenu;
    QAction *removeAction;
    QAction *editAction;
    QAction *toggleAction;
    QModelIndex currentIndex;
};

#endif //TODO_TODOTABLEVIEW_H
