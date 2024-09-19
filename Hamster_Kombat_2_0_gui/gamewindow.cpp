#include "gamewindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GameWindow::GameWindow(QWidget *parent) : QWidget(parent), clickCount(0) {
    clickButton = new QPushButton("Нажми", this);
    clickLabel = new QLabel("чтобы стать богатым", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(clickButton);
    layout->addWidget(clickLabel);

    setLayout(layout);

    connect(clickButton, &QPushButton::clicked, this, &GameWindow::handleButtonClick);
}

void GameWindow::handleButtonClick() {
    clickCount++;
    clickLabel->setText("Заработано: " + QString::number(clickCount));
}
