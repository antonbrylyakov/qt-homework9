#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    connect(udpWorker, &UDPworker::sig_MessageReceived, this, &MainWindow::displayReceivedData);
    connect(ui->pb_Send, &QPushButton::clicked, this, &MainWindow::sendMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayReceivedData(Message msg)
{
    auto str = QString("Принято сообщение от %1:%2, размер сообщения(байт) %3: %4")
            .arg(msg.senderAddress.toString())
            .arg(msg.senderPort)
            .arg(msg.sizeBytes)
            .arg(msg.text);

    ui->te_result->append(str);
}

void MainWindow::sendMessage()
{
    udpWorker->SendDatagram(ui->le_TextToSend->text());
}


