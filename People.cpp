#include "People.h"

People::People() {}
People::People(int ID, string name, string sex, int age, int phone, string email, string address)
{
    this->ID = ID;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->phone = phone;
    this->email = email;
    this->address = address;
}
void People::setId(int ID)
{
    this->ID = ID;
}
int People::getId()
{
    return ID;
}
void People::setName(string name)
{
    this->name = name;
}
string People::getName()
{
    return name;
}
void People::setSex(string sex)
{
    this->sex = sex;
}
string People::getSex()
{
    return sex;
}
void People::setAge(int age)
{
    this->age = age;
}
int People::getAge()
{
    return age;
}
void People::setPhone(int phone)
{
    this->phone = phone;
}
int People::getPhone()
{
    return phone;
}
void People::setEmail(string email)
{
    this->email = email;
}
string People::getEmail()
{
    return email;
}
void People::setAdress(string address)
{
    this->address=address;
}
string People::getAdress()
{
    return address;
}
People::~People(){}