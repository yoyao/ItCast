#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <pthread.h>
#include <sched.h>
#include <QProcess>
#include <QBitmap>

DialogList::DialogList(QWidget *parent) : QWidget(parent),ui(new Ui::DialogList)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/qq.png"));
    //连接子窗口退出的信号和槽
    connect(this,&(this->ChatFormExit),this,&(this->OnChatFormExit));

    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setStyleSheet("background-color:rgba(255,255,255,80%)");

    timer=new QTimer(this);

    connect(timer,&(timer->timeout) ,this,&DialogList::InitWindow);
    timer->start(1000);

    this->ui->toolBox->hide();

}

void DialogList::InitWindow()
{
    this->timer->stop();
    this->setStyleSheet("");

    pthread_t thread;
    int ret;
    void* result;
    ret=pthread_create(&thread,NULL,ReadyFriends,(void*)(&this->map_all));
    if(ret !=0)
    {
        QMessageBox::warning(this,"错误","读取好友列表失败");
        return ;
    }
    //  QMessageBox::warning(this,"提示","读取中。。。");
    ret= pthread_join(thread,&result);
    if(ret!=0)
    {
        QMessageBox::warning(this,"错误","读取好友列表失败");
        return ;
    }
    this->ui->toolBox->showNormal();
    if(map_all.size()>0)
    {
        QToolButton* btn ;
        QMap<int,User*>::iterator it =map_all.begin();
        for(it ;it!=map_all.end();++it)
        {
            btn =new  QToolButton;
            btn->setText(it.value()->GetName());
            btn->setIcon(QIcon(it.value()->GetHead()));
            btn->setIconSize(QPixmap(it.value()->GetHead()).size());
            btn->setAutoRaise(true);
            btn->setToolTip(it.value()->GetName());
            btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            connect(btn,&(btn->clicked),this,[=]()mutable{
                HeaderOnClick(it.value());
            });
            this->ui->GroupLayout->addWidget(btn);
        }


        qDebug()<<map_all.size();
    }

}

void DialogList::HeaderOnClick(User* user)
{
    if(NULL==user)
    {
        return;
    }

    QMap<int,QPair<User*,ChatDialog*>>::const_iterator it=map_chatforms.find(user->GetID());

    if(it!=map_chatforms.end())
    {
        it.value().second->setFocus();
        pthread_mutex_unlock(&this->mutex);
        return ;
    }

    ChatDialog * chat = new ChatDialog();
    QPair<User*,ChatDialog*> pair(user,chat);
    map_chatforms.insert(user->GetID(),pair);
    chat->setWindowTitle(user->GetName());
    chat->SetMParent(this);
    chat->SetUser(user);
    chat->show();

}

void DialogList::OnChatFormExit(ChatDialog *c)
{
    pthread_mutex_lock(&this->mutex);
    map_chatforms.remove(c->m_user->GetID());
    pthread_mutex_unlock(&this->mutex);
    c->close();
    c->destroy(true,true);
}
//子线程处理方法
void* DialogList::ReadyFriends(void *arg_map)
{
    sleep(3);
    QMap<int,User*> *map_all_t =(QMap<int,User*> *)arg_map;
    QFile file("F:\\Itcast\\Projects\\QT\\day27\\QQChat\\user.ct");
    file.open(QFile::ReadOnly);
    char buf[1024];
    User* user;
    int * parr=new int[10];
    //读取JSON配置用户
    while(!file.atEnd())
    {
        file.readLine(buf,1024);
        buf[strlen(buf)-2]=0;
        cJSON* json=cJSON_Parse(buf);

        user = new User;
        user->SetID(cJSON_GetObjectItem(json,"ID")->valueint);
        user->SetName(cJSON_GetObjectItem(json,"name")->valuestring);
        user->SetHead(cJSON_GetObjectItem(json,"head")->valuestring);

        map_all_t->insert(user->GetID(),user);


    }

    return NULL;
}

void DialogList::closeEvent(QCloseEvent *event)
{
    if(this->map_chatforms.size()>0)
    {
        if(QMessageBox::question(this,tr("未关闭的窗口"),tr("检测到有未关闭的聊天窗口，是否关闭？"))==QMessageBox::No)
        {
            event->ignore();
            return;
        }
    }
    this->destroy();
}

DialogList::~DialogList()
{
    QMap<int,QPair<User*,ChatDialog*>>::iterator it;
    for(it=this->map_chatforms.begin();it!=this->map_chatforms.end();++it)
    {
        it.value().second->close();
        delete  it.value().second;
    }
    delete ui;
}


