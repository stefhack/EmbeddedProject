#ifndef WINDOW_H
#define WINDOW_H


#include <QtWidgets>
#include <QtNetwork>
#include <vector>

using namespace std ;


class Window:public QWidget
{
    Q_OBJECT
public:
    Window();
private slots:
    void newConnection();
    void dataReceived();
    void deconnection();
    void serverStart();
private:

    QLabel *_serverState;
    QPushButton *_quitButton;
    QPushButton *_startButton;
    QTcpServer *_server;
    vector<QTcpSocket*> _clients;
    quint16 _messageSize;
};

#endif // WINDOW_H
