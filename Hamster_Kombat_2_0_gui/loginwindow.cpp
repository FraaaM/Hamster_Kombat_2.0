#include "loginwindow.h"
#include "gamewindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QApplication>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(600, 200);
    setWindowIcon(QIcon("D:/PROJECTS_IT/qt_Proj/Hamster_Kombat_2.0/Hamster_Kombat_2_0_gui/hamster_kombat.png"));

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Введите логин");

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Введите пароль");
    passwordInput->setEchoMode(QLineEdit::Password);  // Скрываем вводимые символы пароля

    loginButton = new QPushButton("Войти", this);
    quitButton = new QPushButton("Выйти", this);

    // Размещаем виджеты на форме в вертикальном макете
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    layout->addWidget(quitButton);
    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(quitButton, &QPushButton::clicked, this, &LoginWindow::close);
}

void LoginWindow::onLoginClicked() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    if (username == "1" && password == "1") {
        QMessageBox::information(this, "Успех", "Добро пожаловать!");

        GameWindow *gameWindow = new GameWindow();
        gameWindow->show();

        this->close();

    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль");
    }
}

