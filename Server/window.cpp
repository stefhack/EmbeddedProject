#include "window.h"
#include "QDebug"

Window::Window()
{
    _serverState=new QLabel();
    _quitButton = new QPushButton(tr("Quitter"));
    _startButton=new QPushButton("Démarrer");
    connect(_quitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(_startButton,SIGNAL(clicked()),this,SLOT(serverStart()));
    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget(_serverState);
    layout->addWidget(_startButton);
    layout->addWidget(_quitButton);

    setLayout(layout);
    setWindowTitle(tr("Controle d'accés"));
    setMinimumSize(200,200);
    //serverStart();
}

void Window::newConnection(){
QTcpSocket* newClient=_server->nextPendingConnection();
_clients.push_back(newClient);

connect(newClient,SIGNAL(readyRead()),this,SLOT(dataReceived()));
connect(newClient,SIGNAL(disconnected()),this,SLOT(deconnection()));

}

void Window::dataReceived(){

QTcpSocket* socket=qobject_cast<QTcpSocket*>(sender());
if(socket == 0) return;
QDataStream in(socket);
if(_messageSize==0)
{
if(socket->bytesAvailable()< (int)sizeof(quint16)) return;
in >> _messageSize;

}

if(socket->bytesAvailable() < _messageSize) return;

QString message;
in >> message;
qDebug() << message;
_serverState->setText(message);
}

void Window::deconnection(){

}

void Window::serverStart()
{

_server=new QTcpServer(this);
if(!_server->listen(QHostAddress::Any,1234))
{
_serverState->setText("Le serveur n'a pas pu démarré : "+_server->errorString());
}
else
{
    _serverState->setText("Serveur démarré ");
    connect(_server,SIGNAL(newConnection()),this,SLOT(newConnection()));
}
_messageSize=0;
}
