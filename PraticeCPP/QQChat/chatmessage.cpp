#include "chatmessage.h"

ChatMessage::ChatMessage()
{

}
//序列化到数据流
QDataStream& operator<<(QDataStream &stream,ChatMessage& mes)
{
    stream<<mes.msgtype;
    //<<mes.name<<mes.msg<<mes.time
    stream <<mes.name;
    stream<<mes.msg;
    stream <<mes.time;

    return stream;
}
//从数据流中反序列化
QDataStream& operator>>(QDataStream &stream,ChatMessage& mes)
{
    stream>>mes.msgtype;
    stream>>mes.name;
    stream>>mes.msg;
    stream>>mes.time;
    return stream;
}

void ChatMessage::SetMsgType(int type)
{
    this->msgtype = type;
}

void ChatMessage::SetMsg(QString& msg)
{
    this->msg = msg;
}

void ChatMessage::SetName(QString& uname)
{
    this->name = uname;
}

void ChatMessage::SetTime(QDateTime& utime)
{
    this->time =utime;
}

int ChatMessage::GetMsgType()
{
    return this->msgtype;
}

QString ChatMessage::GetMsg()
{
    return this->msg;
}

QString ChatMessage::GetName()
{
    return this->name;
}

QDateTime ChatMessage::GetTime()
{
    return this->time;
}
