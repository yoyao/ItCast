#include "chatdialog.h"
#include "ui_chatdialog.h"
#include "dialoglist.h"

ChatDialog::ChatDialog(QWidget *parent) :QWidget(parent),ui(new Ui::ChatDialog),msgtype(USERENT)
{
    ui->setupUi(this);

    InitWindow();

    //绑定readyRead
    connect(this->UdpHandle,&QUdpSocket::readyRead,this,&(this->ReceiveMessage));

}

void ChatDialog::InitWindow()
{
    this->UdpHandle = new QUdpSocket(this);
    this->port = 2213;\
    //               绑定端口号  绑定模式  共享地址，断线重连
    UdpHandle->bind(this->port,QUdpSocket::ShareAddress |QUdpSocket::ReuseAddressHint);
}

void ChatDialog::closeEvent(QCloseEvent *event)
{
    this->msgtype = USERLEAVE;
    QString s= "测试离开";
    SendMessage(s);
    DialogList* m_parent= (DialogList*)this->m_Parent;//得到它的父类
    //触发父类的聊天窗口推出信号
    emit m_parent->ChatFormExit(this);
    this->UdpHandle->close();
    qDebug()<<"close";

}

void ChatDialog::resizeEvent(QResizeEvent *event)
{
    QString s= "测试进入";
    SendMessage(s);
}

void ChatDialog::SetUser(User* user)
{
    this->m_user = user;
}

void ChatDialog::SetMParent(QWidget *mparent)
{
    this->m_Parent = mparent;
}

void ChatDialog::on_btn_exit_clicked()
{
    //关闭方法会触发关闭事件
    this->close();
    // this->destroy(true,true);
}
//发送按钮点击事件
void ChatDialog::on_btn_send_clicked()
{
    QString msg = this->ui->txt_write->toHtml();
    if(msg.isEmpty()|| msg.isNull())
    {
        QMessageBox::warning(this,"提示","输入内容为空");
        return;
    }
    this->msgtype=CHATMSG;
    SendMessage(msg);
}
//用户进入
void ChatDialog::OnUserEnter()
{
    QString str="["+this->chatmsg.GetName()+"] 上线了";
    this->ui->txt_read->append(str.toUtf8());
}
//用户离开
void ChatDialog::OnUserLeave()
{
    QString str="["+this->chatmsg.GetName()+"] 离开了";
    this->ui->txt_read->append(str.toUtf8());
}
//发送消息
void ChatDialog::SendMessage(QString& msg)
{
    /*{"type":"","msg":"","username":"","time":""}*/

    /*原来的拼JSON字符串
    QString SendMsg="{\"type\":\"";
    SendMsg+=QString::number(this->msgtype);
    SendMsg+="\",\"msg\":\"";
    SendMsg+=msg;
    SendMsg+="\",\"username\":\"";
    QDateTime time =QDateTime::currentDateTime();
    SendMsg+="\",\"time\":\""+time.toString("yyyy-MM-dd hh:mm:ss")+"\"";
    SendMsg+="}";
*/

    QDateTime time =QDateTime::currentDateTime();

    ChatMessage mesg;
    //设置临时消息类
    mesg.SetMsg(msg);
    mesg.SetTime(time);
    mesg.SetMsgType((int)this->msgtype);
    QString str=" ";
    if(this->m_user != NULL)
    {
        str=this->m_user->GetName();
    }

    mesg.SetName(str);

    QByteArray array;
    QDataStream stream(&array,QIODevice::ReadWrite);
    //序列化消息类
    stream<<mesg;
    //发送带有序列化消息类的数据流
    UdpHandle->writeDatagram(array,QHostAddress::Broadcast,port);

    this->ui->txt_write->clear();
}

void ChatDialog::ShowRecvMessage()
{
    QString str="["+this->chatmsg.GetName()+"] "+this->chatmsg.GetTime().toString("yyyy-MM-dd hh:mm:ss");
    this->ui->txt_read->append(str);
    this->ui->txt_read->append(this->chatmsg.GetMsg());
}

//接收消息
void ChatDialog::ReceiveMessage()
{

    if(!UdpHandle->hasPendingDatagrams())
    {
      return ;
    }
     QHostAddress SenderAddr;
     quint16 SenderPort;
    qint64 size = UdpHandle->pendingDatagramSize();

    QByteArray array = QByteArray(size,0);
    //读取消息  获取发送方的IP地址和端口
    UdpHandle->readDatagram(array.data(),size,&SenderAddr,&SenderPort);

    QDataStream stream(&array,QIODevice::ReadWrite);
    //反序列化
    ChatMessage mes;
    stream>>mes;
    this->chatmsg = mes;
    //分发消息
    MessageIssue();
}

//清除聊天记录按钮点击事件
void ChatDialog::on_btn_clear_clicked()
{
    this->ui->txt_read->clear();
}
//消息分发
int ChatDialog::MessageIssue()
{
    //消息类型没有为0的情况 出现0 就是序列化出错了
    if(this->chatmsg.GetMsgType()==0)
    {
        return -1;
    }

    switch (this->chatmsg.GetMsgType())
    {
    case USERENT:
    {
        OnUserEnter();
        break;
    }
    case USERLEAVE:
    {
        OnUserLeave();
        break;
    }
    case CHATMSG:
    {
        ShowRecvMessage();
        break;
    }
    default:
    {
        break;
    }
    }

    return 0;
}

void ChatDialog::on_btn_color_clicked()
{
    QColor color =QColorDialog::getColor(QColor(0,0,0),this,"设置字体颜色");
    this->ui->txt_write->setTextColor(color);
}

//倾斜
void ChatDialog::on_btn_italic_clicked()
{
    if(this->ui->txt_write->fontItalic())
    {
        this->ui->txt_write->setFontItalic(0);
        return;
    }
    this->ui->txt_write->setFontItalic(1);
}
//加粗
void ChatDialog::on_btn_blod_clicked(bool checked)
{

    if(this->ui->txt_write->fontInfo().weight()==QFont::Normal)
    {
        this->ui->txt_write->setFontWeight(QFont::Bold);
    }
    else
    {
        this->ui->txt_write->setFontWeight(QFont::Normal);
    }
}
//下划线
void ChatDialog::on_btn_underline_clicked(bool checked)
{
    if(this->ui->txt_write->fontUnderline())
    {
        this->ui->txt_write->setFontUnderline(0);
        return;
    }
    this->ui->txt_write->setFontUnderline(1);
}
//设置字体
void ChatDialog::on_comb_font_currentFontChanged(const QFont &f)
{
    this->ui->txt_write->setFont(f);
}
//字体大小
void ChatDialog::on_comb_fontsize_currentIndexChanged(int index)
{
    this->ui->txt_write->setFontPointSize(this->ui->comb_fontsize->itemText(index).toDouble());
}

ChatDialog::~ChatDialog()
{
    delete ui;
    delete UdpHandle;
}
