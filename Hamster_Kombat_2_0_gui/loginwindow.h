#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginClicked();  // Проверка логина

private:
    QLineEdit *usernameInput;  // Поле для ввода логина
    QLineEdit *passwordInput;  // Поле для ввода пароля
    QPushButton *loginButton;  // Кнопка входа
};

#endif // LOGINWINDOW_H


