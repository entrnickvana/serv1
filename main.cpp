#include <QCoreApplication>
#include <QTcpSocket>
#include <QTcpServer>
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sockettest Csocket;
    Csocket.Connect();

    return a.exec();
}
