#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QWidget>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDevice>
#include <QTextStream>
#include <QToolButton>
#include <QMap>
#include <QMessageBox>
#include <QPair>
#include <iterator>
#include <unistd.h>
#include <sys/types.h>
#include <QTimer>
#include "cJSON.h"
#include "chatdialog.h"
#include "user.h"


namespace Ui {
class DialogList;
}


/*
新开一个线程，用来实时保存聊天记录
另一个线程用来保存操作记录
*/

class DialogList : public QWidget
{
    Q_OBJECT
    friend void* CreateNewChat(void* u);
signals:
    void ChatFormExit(ChatDialog* c);
public:
    explicit DialogList(QWidget *parent = 0);
    ~DialogList();

protected:
    virtual void closeEvent(QCloseEvent* event);

private:
    void HeaderOnClick(User* user);
    void InitWindow();
    //子窗口关闭事件
    void OnChatFormExit(ChatDialog* c);
    static void *ReadyFriends(void *arg_map);

private:
    Ui::DialogList *ui;
    ChatDialog* c =NULL;
    QMap<int,QPair<User*,ChatDialog*>> map_chatforms;
    QMap<int,User*> map_all;
    pthread_mutex_t mutex;
    QTimer *timer;
};

#endif // DIALOGLIST_H
