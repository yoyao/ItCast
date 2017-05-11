#ifndef USER_H
#define USER_H
#include <QString>



class User
{
public:
    User();
    void SetID(int id);
    void SetName(QString name);
    void SetHead(QString head);
    int GetID();
    QString GetName();
    QString GetHead();
private:
   int ID;
   QString Name;
   QString Head;
};


#endif // USER_H

