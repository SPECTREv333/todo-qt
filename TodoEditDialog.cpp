//
// Created by leonardo on 30/07/24.
//

#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>
#include "TodoEditDialog.h"

TodoEditDialog::TodoEditDialog(std::shared_ptr<Todo> todo, QWidget *parent)
        : QDialog(parent), todo(todo) {
    setWindowTitle("Todo Editor");

    // Creazione dei widget
    QLabel *titleLabel = new QLabel("Title:");
    titleEdit = new QLineEdit(this);
    titleEdit->setText(todo->getTitle());

    QLabel *descriptionLabel = new QLabel("Description:");
    descriptionEdit = new QTextEdit(this);
    descriptionEdit->setText(todo->getDescription());

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    // Layout
    auto *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(titleEdit);

    auto *descriptionLayout = new QVBoxLayout;
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addWidget(descriptionEdit);

    auto *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(descriptionLayout);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    // Collegamento dei segnali
    connect(okButton, &QPushButton::clicked, this, &TodoEditDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &TodoEditDialog::reject);
}

std::shared_ptr<Todo> TodoEditDialog::getTodo() const {
    return todo;
}

void TodoEditDialog::accept() {
    if (titleEdit->text().isEmpty()) {
        // Puoi mostrare un messaggio di errore se il titolo è vuoto
        QMessageBox::warning(this, "Error", "Title cant be empty!");
        return;
    }

    todo->setTitle(titleEdit->text());
    todo->setDescription(descriptionEdit->toPlainText());

    QDialog::accept();
}
