//
// Created by leonardo on 30/07/24.
//

#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>
#include "TodoEditDialog.h"

TodoEditDialog::TodoEditDialog(std::shared_ptr<Todo> todo, QWidget *parent)
        : QDialog(parent), todo(todo) {
    setWindowTitle("Editor dell'attività");

    // Creazione dei widget
    QLabel *titleLabel = new QLabel("Titolo:");
    titleEdit = new QLineEdit(this);
    titleEdit->setText(todo->getTitle().c_str());

    QLabel *descriptionLabel = new QLabel("Descrizione:");
    descriptionEdit = new QTextEdit(this);
    descriptionEdit->setText(todo->getDescription().c_str());

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Annulla");

    // Layout
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(titleEdit);

    QVBoxLayout *descriptionLayout = new QVBoxLayout;
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addWidget(descriptionEdit);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
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
        QMessageBox::warning(this, "Errore", "Il titolo non può essere vuoto!");
        return;
    }

    // TODO: use QString everywhere, its just painful to convert back and forth
    todo->setTitle(titleEdit->text().toStdString());
    todo->setDescription(descriptionEdit->toPlainText().toStdString());

    QDialog::accept();
}
