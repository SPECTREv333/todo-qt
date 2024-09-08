# Todo Application

This is a simple Todo application written in C++ using the Qt framework. The application allows users to create, edit, and manage their todo items.

> [!NOTE]
> This app does not use Qt Signals and slots in a traditional manner, this is an exercise to apply MVC and Observer patterns

> [!WARNING]
> googletest comes as submodule!
>```sh
>git clone --recurse-submodules https://github.com/SPECTREv333/todo-qt.git
>``` 

## Features

- Add, edit, and delete todo items
- Set start and end dates for todo items
- Serialize and deserialize todo items
- Observer pattern for notifying changes

## Requirements

- C++17 or later
- Qt 5.15 or later
- CMake 3.10 or later
- GoogleTest for unit testing
