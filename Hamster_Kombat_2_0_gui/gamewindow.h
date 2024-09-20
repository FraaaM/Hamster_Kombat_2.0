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
    uint clickCount;
    QLabel *clickLabel;     // Метка для отображения счётчика
    QPushButton *clickButton;
    QPushButton *quitButton;
};

#endif // GAMEWINDOW_H
