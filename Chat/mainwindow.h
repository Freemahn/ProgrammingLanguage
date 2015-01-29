#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTextLayout>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Ui::MainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void on_send_btn_clicked();
    void on_login_btn_clicked();
    void readyRead();

    void on_message_edit_returnPressed();
    void on_nickname_edit_returnPressed();

private:
    QUdpSocket *socket;
    QString name;//user nickname
    const int PORT=5555;
};

#endif // MAINWINDOW_H
