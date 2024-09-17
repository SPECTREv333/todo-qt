//
// Created by leonardo on 30/07/24.
//

#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDateTimeEdit>
#include "TodoEditDialog.h"

TodoEditDialog::TodoEditDialog(Todo& todo, QWidget *parent) // TODO: extract gui creation to a separate class
        : QDialog(parent), todo(todo) {
    setWindowTitle("Todo Editor");

    // Creazione dei widget
    QLabel *titleLabel = new QLabel("Title:", parent);
    titleEdit = new QLineEdit(this);
    titleEdit->setText(todo.getTitle());

    QLabel *descriptionLabel = new QLabel("Description:", this);
    descriptionEdit = new QTextEdit(this);
    descriptionEdit->setText(todo.getDescription());

    QLabel *startEditLabel = new QLabel("Start date:", this);
    startEdit = new QDateTimeEdit(todo.getStartDate(), this);
    startEdit->setCalendarPopup(true);
    startEdit->setDisplayFormat("dd/MM/yyyy hh:mm");

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    auto layoutWidget = new QWidget(this);
    auto mainLayout = new QVBoxLayout(layoutWidget);
    layoutWidget->setLayout(mainLayout);

    // Layout
    auto titleLayoutWidget = new QWidget(layoutWidget);
    titleLayoutWidget->setLayout(new QHBoxLayout(this));
    //auto titleLayout = new QHBoxLayout(layoutWidget);
    titleLayoutWidget->layout()->addWidget(titleLabel);
    titleLayoutWidget->layout()->addWidget(titleEdit);

    auto descriptionLayoutWidget = new QWidget(layoutWidget);
    descriptionLayoutWidget->setLayout(new QVBoxLayout(this));
    descriptionLayoutWidget->layout()->addWidget(descriptionLabel);
    descriptionLayoutWidget->layout()->addWidget(descriptionEdit);

    auto startDateLayoutWidget = new QWidget(layoutWidget);
    startDateLayoutWidget->setLayout(new QVBoxLayout(this));
    startDateLayoutWidget->layout()->addWidget(startEditLabel);
    startDateLayoutWidget->layout()->addWidget(startEdit);

    auto buttonsLayoutWidget = new QWidget(layoutWidget);
    buttonsLayoutWidget->setLayout(new QHBoxLayout(this));
    buttonsLayoutWidget->layout()->addWidget(okButton);
    buttonsLayoutWidget->layout()->addWidget(cancelButton);

    mainLayout->addWidget(titleLayoutWidget);
    mainLayout->addWidget(startDateLayoutWidget);
    mainLayout->addWidget(descriptionLayoutWidget);
    mainLayout->addWidget(buttonsLayoutWidget);

    setLayout(mainLayout);

    // Collegamento dei segnali
    connect(okButton, &QPushButton::clicked, this, &TodoEditDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &TodoEditDialog::reject);
}

Todo& TodoEditDialog::getTodo() const {
    return todo;
}

void TodoEditDialog::accept() {
    if (titleEdit->text().isEmpty()) {
        // Puoi mostrare un messaggio di errore se il titolo è vuoto
        QMessageBox::warning(this, "Error", "Title cant be empty!");
        return;
    }

    todo.setTitle(titleEdit->text());
    todo.setDescription(descriptionEdit->toPlainText());
    todo.setStartDate(startEdit->dateTime());

    QDialog::accept();
}
