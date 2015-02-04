#include <QCoreApplication>
#include "client.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
client cli;
cli.connect();
string message;
std::cin >> message;
cli.sendMessage(QString::fromStdString(message));

    return a.exec();
}
