//
// Created by leonardo on 13/09/24.
//

#include "TodoListQAbstractTableModelAdapter.h"
#include "Todo.h"

TodoListQAbstractTableModelAdapter::TodoListQAbstractTableModelAdapter(TodoList *todoList, QObject *parent)
    : QAbstractTableModel(parent), todoList(todoList) {}

int TodoListQAbstractTableModelAdapter::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return todoList->size();
}

int TodoListQAbstractTableModelAdapter::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3; // Assuming columns for Title, Description, and Status
}

QVariant TodoListQAbstractTableModelAdapter::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    auto todo = todoList->getTodo(index.row());
    switch (index.column()) {
        case 0:
            return todo.getTitle();
        case 1:
            return todo.getStartDate();
        case 2:
            return todo.isDone() ? "Done" : "Not Done";
        default:
            return QVariant();
    }
}

QVariant TodoListQAbstractTableModelAdapter::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return "Title";
            case 1:
                return "When";
            case 2:
                return "Status";
            default:
                return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags TodoListQAbstractTableModelAdapter::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return QAbstractTableModel::flags(index);
}

void TodoListQAbstractTableModelAdapter::redraw() {
    beginResetModel();
    endResetModel();
}
