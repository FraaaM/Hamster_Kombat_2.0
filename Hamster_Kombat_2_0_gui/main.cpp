#include <QApplication>
#include "loginwindow.h"
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();

    return app.exec();
}

