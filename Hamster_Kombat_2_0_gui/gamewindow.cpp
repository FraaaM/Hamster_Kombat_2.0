#include "gamewindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSettings>


GameWindow::GameWindow(QWidget *parent) : QWidget(parent), clickCount(0) {
    setFixedSize(520, 470);
    setStyleSheet("background-color: black;");
    setWindowIcon(QIcon("D:/PROJECTS_IT/qt_Proj/Hamster_Kombat_2.0/Hamster_Kombat_2_0_gui/hamster_kombat.png"));

    clickButton = new QPushButton(this);
    clickButton->setIcon(QIcon("D:/PROJECTS_IT/qt_Proj/Hamster_Kombat_2.0/Hamster_Kombat_2_0_gui/hamster_coin.webp"));
    clickButton->setIconSize(QSize(250, 250));

    quitButton = new QPushButton("Выйти", this);
    quitButton->setStyleSheet(
        "font-size: 32px; "
        "color: #ffd700; "
        "font-weight: bold;");

    clickLabel = new QLabel("Нажми, чтобы стать богатым!", this);
    clickLabel->setStyleSheet("font-size: 32px; color: #ffd700; font-weight: bold;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(clickButton);
    layout->addWidget(clickLabel);
    layout->addWidget(quitButton);
    setLayout(layout);

    loadClickCount();

    connect(clickButton, &QPushButton::clicked, this, &GameWindow::handleButtonClick);
    connect(quitButton, &QPushButton::clicked, this, &GameWindow::close);    

}

void GameWindow::handleButtonClick() {
    clickCount++;
    clickLabel->setText("Заработано: " + (QString::number(clickCount)));

}

// Сохраняем счёт при закрытии программы
void GameWindow::closeEvent(QCloseEvent *event) {
    saveClickCount();
    QWidget::closeEvent(event);
}

void GameWindow::saveClickCount() {
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("clickCount", clickCount);
}

void GameWindow::loadClickCount() {
    QSettings settings("MyCompany", "MyApp");
    clickCount = settings.value("clickCount", 0).toInt();  // Загружаем счёт, если не сохранён - по умолчанию 0
    clickLabel->setText("Заработано: " + (QString::number(clickCount)));

}


