#include "sockettest.h"


sockettest::sockettest(QObject *parent) :
    QObject(parent)
{
}


void sockettest::Connect()
{
    socket=new QTcpSocket(this);
    qDebug()<<"WELCOME TO CLIENT";
    std::cout<<"Enter the port no for connetion=";
    QTextStream qtin(stdin);
    QString Qip_addr;
    quint16 clientport;
    std::cin >> clientport;

    std::cout<<"Enter the IP ADDR";
    qtin >> Qip_addr;

    socket->connectToHost(Qip_addr,clientport);
    if(socket->waitForConnected(30000))
    {
        qDebug()<<"Connected";
        socket->write("start");
        socket->flush();
        socket->waitForBytesWritten(10000);
    }
    else
    {
        qDebug()<<"Not connected";
    }
    socket->waitForReadyRead(1000);
    if(socket->readLine()=="start")
    {
        QString servermove="something";
        while(servermove!="close")
        {
            char move[9];
            socket->waitForReadyRead(30000);
            servermove=socket->readLine();
            qDebug()<<servermove;
            std::cout<<"Enter the move=";
            std::cin>>move;
            socket->write(move);
            socket->flush();
            socket->waitForBytesWritten(10000);

        }
    }

    socket->close();
    socket->waitForDisconnected(3000);
}
