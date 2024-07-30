//
// Created by leonardo on 30/07/24.
//

#ifndef TODO_TODOEDITDIALOG_H
#define TODO_TODOEDITDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include "Todo.h"

class TodoEditDialog : public QDialog {
    Q_OBJECT
public:
    TodoEditDialog(std::shared_ptr<Todo> todo, QWidget *parent = nullptr);

    std::shared_ptr<Todo> getTodo() const;

private slots:
    void accept() override;

private:
    std::shared_ptr<Todo> todo;
    QLineEdit *titleEdit;
    QTextEdit *descriptionEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
};



#endif //TODO_TODOEDITDIALOG_H
