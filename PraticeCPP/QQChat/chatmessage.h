#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QDataStream>

class ChatMessage
{
public:
    explicit ChatMessage();

    friend QDataStream& operator<<(QDataStream& stream,ChatMessage& mes);//序列化到数据流
    friend QDataStream& operator>>(QDataStream& stream,ChatMessage& mes);//反序列化

public :
    void SetMsgType(int type);
    void SetMsg(QString& msg);
    void SetName(QString& uname);
    void SetTime(QDateTime& utime);

    int GetMsgType();
    QString GetMsg();
    QString GetName();
    QDateTime GetTime();
private:
    int msgtype;
    QString msg;
    QString name;
    QDateTime time;

};

QDataStream& operator<<(QDataStream& stream,ChatMessage& mes);//序列化到数据流
QDataStream& operator>>(QDataStream& stream,ChatMessage& mes);//反序列化


#endif // CHATMESSAGE_H
