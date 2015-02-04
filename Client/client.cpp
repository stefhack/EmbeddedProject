#include "client.h"


client::client()
{
    _socket=new QTcpSocket(this);
    QObject::connect(_socket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    QObject::connect(_socket,SIGNAL(connected()),this,SLOT(connection()));
     QObject::connect(_socket,SIGNAL(disconnected()),this,SLOT(deconnection()));
    QObject::connect(_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(erroSocket(QAbstractSocket::SocketError)));
    _sizeMessage=0;
}
void client::connect(){
    _socket->abort();
    _socket->connectToHost("127.0.0.1",1234);
}

void client::sendMessage(QString &message){
QByteArray paquet;
QDataStream out(&paquet,QIODevice::WriteOnly);
out << (quint16) 0;
out << message;
out.device()->seek(0);
out << (quint16)(paquet.size() - sizeof(quint16));
_socket->write(paquet);

}

void client::dataReceived(){

}

void client::connection(){
qDebug()<< "vous êtes bien connecté au serveur";
}

void client::deconnection(){

}

void client::erroSocket(QAbstractSocket::SocketError error){

    QString message;
    switch(error)
    {
    case QAbstractSocket::HostNotFoundError:
        message = "Serveur non trouvé";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        message = "Connexion refusée ";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        message = "Connexion coupée par le serveur ";
        break;

    default:
        message= _socket->errorString();

    }

qDebug()<< message;
}
