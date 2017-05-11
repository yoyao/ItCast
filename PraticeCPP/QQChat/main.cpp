#include <QApplication>
#include "dialoglist.h"
#include "chatdialog.h"
#include "chatmessage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogList dialog;
    //窗口退出时，关闭当前进程

    dialog.show();

    return a.exec();
}
