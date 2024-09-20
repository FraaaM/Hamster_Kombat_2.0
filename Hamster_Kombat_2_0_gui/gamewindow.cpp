#include "gamewindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GameWindow::GameWindow(QWidget *parent) : QWidget(parent), clickCount(0) {
    setFixedSize(500, 400);
    setStyleSheet("background-color: black;");
    setWindowIcon(QIcon("D:/PROJECTS_IT/qt_Proj/Hamster_Kombat_2.0/Hamster_Kombat_2_0_gui/hamster_kombat.png"));

    clickButton = new QPushButton(this);
    clickButton->setIcon(QIcon("D:/PROJECTS_IT/qt_Proj/Hamster_Kombat_2.0/Hamster_Kombat_2_0_gui/hamster_coin.webp"));  // Устанавливаем иконку для кнопки
    clickButton->setIconSize(QSize(250, 250));  // Увеличиваем размер изображения на кнопке

    clickLabel = new QLabel("Нажми чтобы стать богатым", this);
    clickLabel->setStyleSheet("font-size: 32px; color: #ffd700; font-weight: bold;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(clickButton);
    layout->addWidget(clickLabel);

    setLayout(layout);

    connect(clickButton, &QPushButton::clicked, this, &GameWindow::handleButtonClick);
}

void GameWindow::handleButtonClick() {
    clickCount++;
    clickLabel->setText("Заработано: " + (QString::number(clickCount)));


}
