#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class QLabel;
class QPushButton;

class GameWindow : public QWidget {
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);

private slots:
    void handleButtonClick();  // Обработчик нажатия кнопки

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    uint clickCount;
    QLabel *clickLabel;     // Метка для отображения счётчика
    QPushButton *clickButton;
    QPushButton *quitButton;

    void onButtonClick();
    void saveClickCount();
    void loadClickCount();
};

#endif // GAMEWINDOW_H
