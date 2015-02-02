#include <QApplication>
#include <QDebug>
#include "server.h"
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Server server;
    //server.start();
    Window window;
    window.show();
   return a.exec();
}
