#include "mainwindow.h"
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::Any, 5555, QUdpSocket::ReuseAddressHint);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MainWindow::on_login_btn_clicked()
{
    name = nickname_edit->text().trimmed();
    chat_log->append("<" + name + "> " + " online");
}

void MainWindow::readyRead() {
    while(socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 port;
        socket->readDatagram(buffer.data(), buffer.size(), &sender, &port);
        QString line = QString::fromUtf8(buffer).trimmed();
        QRegExp messageRegex("^([^:]+):*$");
        if (messageRegex.indexIn(line) != -1) {
            QString user = messageRegex.cap(1).trimmed();

            QString message = messageRegex.cap(2);
            bool newbee = true;
            for (int i = 0; i < listWidget->count(); i++)
                if (listWidget->item(i)->text() == user) {
                    newbee = false;
                    break;
                }
            if (newbee)
                listWidget->addItem(user);

            chat_log->append("<" + user + ">: " + message);
        }
    }
}

void MainWindow::on_send_btn_clicked()
{
        QString message = message_edit->text().trimmed();
        if(!message.isEmpty()) {
            QByteArray datagram;
            datagram.append(name + ":" + QString(message + "\n"));
            datagram.append("\n");
            socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 5555);
        }

        listWidget->addItem(name);
        message_edit->clear();
        message_edit->setFocus();

}
