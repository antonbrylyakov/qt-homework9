#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QHostAddress>

struct Message
{
    QHostAddress senderAddress;
    int senderPort;
    qsizetype sizeBytes;
    QString text;
};

#endif // MESSAGE_H
