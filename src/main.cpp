#include <QApplication>
#include <QMainWindow>
// #include <boost/core/addressof.hpp>
#include <QAbstractOAuth2>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include "spdlog/spdlog.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    spdlog::info("Witam w spdlogu!");
    // std::cout << boost::addressof(app) << std::endl;
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Moje Okno - test");
    mainWindow.show();

    return app.exec();
}