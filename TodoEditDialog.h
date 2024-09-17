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
    explicit TodoEditDialog(Todo& todo, QWidget *parent = nullptr);

    Todo& getTodo() const;

private slots:
    void accept() override;

private:
    Todo& todo;
    QLineEdit *titleEdit;
    QTextEdit *descriptionEdit;
    QDateTimeEdit *startEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
};



#endif //TODO_TODOEDITDIALOG_H
