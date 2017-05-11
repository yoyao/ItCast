#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>
#include <QMessageBox>
#include <QMap>
#include <QUdpSocket>
#include <QString>
#include <QHeaderView>
#include <QTableWidget>
#include <QCloseEvent>
#include <QDateTime>
#include <string>
#include <QBuffer>
#include <QColorDialog>
#include <QFont>
#include <QFontDialog>
#include "user.h"
#include "chatmessage.h"

//#include "dialoglist.h"

using namespace std;

namespace Ui {
class ChatDialog;
}


enum MsgType {
CHATMSG=0x0001,
USERENT=0x0002,
USERLEAVE=0x0003
};


class ChatDialog : public QWidget
{
    Q_OBJECT
    friend class DialogList;
public:
    explicit ChatDialog(QWidget *parent = 0);
    ~ChatDialog();
    void SetUser(User* user);
    void SetMParent(QWidget* mparent);
    void InitWindow();

protected:
     void closeEvent(QCloseEvent* event);
     void resizeEvent(QResizeEvent *event);

private slots:
    void on_btn_exit_clicked();//退出按钮点击事件
    void OnUserEnter();//用户进入
    void OnUserLeave();//用户离开
    void ShowRecvMessage();//显示聊天信息
    void SendMessage(QString &msg);//发送消息
    void ReceiveMessage();//接收消息
    void on_btn_send_clicked();//发送按钮点击事件
    void on_btn_clear_clicked();//清除聊天记录的按钮点击事件

    //消息分发
    int MessageIssue();

    void on_btn_color_clicked();

    void on_btn_italic_clicked();

    void on_btn_blod_clicked(bool checked);

    void on_btn_underline_clicked(bool checked);

    void on_comb_font_currentFontChanged(const QFont &f);

    void on_comb_fontsize_currentIndexChanged(int index);

private:
    Ui::ChatDialog *ui;
    User* m_user;
    QWidget* m_Parent;
    QUdpSocket* UdpHandle;
    quint16 port;
    MsgType msgtype;//当前状态下的消息类型
    ChatMessage chatmsg;
};

#endif // CHATDIALOG_H
