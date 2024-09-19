#include "loginwindow.h"
#include "gamewindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Введите логин");

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Введите пароль");
    passwordInput->setEchoMode(QLineEdit::Password);  // Скрываем вводимые символы пароля

    loginButton = new QPushButton("Войти", this);

    // Размещаем виджеты на форме в вертикальном макете
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    setLayout(layout);

    // Связываем кнопку входа с методом проверки логина
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
}

void LoginWindow::onLoginClicked() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    if (username == "admin" && password == "1234") {
        QMessageBox::information(this, "Успех", "Добро пожаловать!");

        GameWindow *gameWindow = new GameWindow();
        gameWindow->show();

        this->close();

    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль");
    }
}

