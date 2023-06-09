#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "UdpWorker.h"

#define TIMER_DELAY 1000
// Можно было бы отправлять все сообщения на один порт и обрабатывать одинаково, но это потребует разработки протокола,
// чтобы в общем случае отличать сообщения о текущем времени от произвольных
// в задании требуется освоить использование нескольких сокетов в одном приложении, поэтому
// для простоты сообщения о времени и остальные будем отправлять на разные порты
#define SEND_TO_PORT1 12345
#define SEND_TO_PORT2 12346
#define LISTEN_PORT1 12345
#define LISTEN_PORT2 12346

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void displayReceivedDateTimeData(QNetworkDatagram datagram);
    void displayReceivedMessageData(QNetworkDatagram datagram);
    void sendMessage();
    void on_pb_Start_clicked();
    void on_pb_Stop_clicked();

private:
    uint32_t counterPck = 0;
    Ui::MainWindow *ui;
    QTimer* timer;
    UDPworker* udpWorkerTimer;
    UDPworker* udpWorkerMessage;
    void clearIfNeeded();
};
#endif // MAINWINDOW_H
