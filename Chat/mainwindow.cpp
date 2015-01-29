#include "mainwindow.h"
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    socket = new QUdpSocket(this);
    name = "DEFAULT";

    socket->bind(QHostAddress::Any, PORT, QUdpSocket::ReuseAddressHint);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QByteArray datagram;
    datagram.append(name + QString(":is online"));
    socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
}

void MainWindow::on_login_btn_clicked()
{
    QString new_name = nickname_edit->text().trimmed( );
    if( new_name == "" ||new_name==name) return;
    QByteArray datagram;
    datagram.append(name+ QString(":is offline"));
    socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
    name = new_name;
    datagram.clear();
    datagram.append(name + QString(":is online"));
    socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);


}

void MainWindow::readyRead() {
    while(socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 port;
        socket->readDatagram(buffer.data(), buffer.size(), &sender, &port);
        QString line = QString::fromUtf8(buffer).trimmed();
        QRegExp messageRegex("^([^:]+):(.*)$");
        if (messageRegex.indexIn(line) != -1) {
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);
            bool newbee = true;
            for (int i = 0; i < listWidget->count(); i++)
                if (listWidget->item(i)->text() == user) {
                    newbee = false;
                    break;
                }
            if (newbee){
                listWidget->addItem(user);               
            }
            if(message == "is online"||message == "is offline")
                chat_log->append("<" + user + "> " + message);
            else
                chat_log->append("<" + user + ">: " + message);
        }
    }
}

void MainWindow::on_send_btn_clicked()
{
        QString message = message_edit->text().trimmed();
        if(!message.isEmpty()) {
            QByteArray datagram;
            datagram.append(name + QString(":") + message);
            datagram.append("\n");
            socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
        }


        message_edit->clear();
        message_edit->setFocus();

}

void MainWindow::on_message_edit_returnPressed()
{
    on_send_btn_clicked();

}

void MainWindow::on_nickname_edit_returnPressed()
{
    on_login_btn_clicked();
}
