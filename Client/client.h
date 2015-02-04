#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>

class client:public QObject
{
    Q_OBJECT
public:
    client();
    void connect();
    void sendMessage(QString &message);
private slots:
    void dataReceived();
    void connection();
    void deconnection();
    void erroSocket(QAbstractSocket::SocketError);
private:
    QTcpSocket * _socket;
    quint16 _sizeMessage;
};

#endif // CLIENT_H
