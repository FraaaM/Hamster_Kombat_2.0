#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

class QLabel;
class QPushButton;

class GameWindow : public QWidget {
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);

private slots:
    void handleButtonClick();  // Обработчик нажатия кнопки

private:
    uint clickCount;         // Счётчик нажатий111
    QLabel *clickLabel;     // Метка для отображения счётчика
    QPushButton *clickButton; // Кнопка для нажатий
};

#endif // GAMEWINDOW_H
