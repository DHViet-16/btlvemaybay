#pragma once
#include <iostream>
#include <cstring>
#include "Date.h"
#include <vector>
using namespace std;

class People
{
protected:
    int ID;
    string name;
    string sex;
    int age;
    int phone;
    string email;
    string address;
public:
    People();
    People(int , string ,string ,int , int,  string , string );
    void setId(int);
    int getId();
    void setName(string);
    string getName();
    void setSex(string);
    string getSex();
    void setAge(int);
    int getAge();
    void setPhone(int);
    int getPhone();
    void setEmail(string);
    string getEmail();
    void setAdress(string);
    string getAdress();
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void readFilePeople(ifstream &) = 0;
    virtual void exportFilePeople(ofstream &) = 0;
    ~People();
};