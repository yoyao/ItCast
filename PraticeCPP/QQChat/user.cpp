#include "user.h"

User::User()
{

}

void User::SetID(int id)
{
  this->ID =id;
}

void User::SetName(QString name)
{
 this->Name = name;
}

void User::SetHead(QString head)
{
 this->Head = head;
}

int User::GetID()
{
  return this->ID;
}

QString User::GetName()
{
   return this->Name;
}

QString User::GetHead()
{
 return this->Head;
}
