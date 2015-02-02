#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void start();
signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;
};

#endif // MYTCPSERVER_H
