#pragma once
#include <iostream>
#include <vector>
#include"People.h"
#include "Customer.h"
#include "Manager.h"
#include"AccountList.h"
#include <sstream>
#include <string.h>
using namespace std;

class PEOPLELIST
{
    private:
        vector<People*>PeopleList;
    public:
        PEOPLELIST();
        void setPeopleList(vector<People*>);
        vector<People*> getPeopleList();
        void input(ACCOUNTSLIST &);
        void output();
        void outputCustomer();
        void outputManager();
        void outputAllPeople();
        bool checkDuplicatedIdPeople(int);
        int findPeopleById(int);
        void findPeopleByName(string);
        void changePeopleInformation(string);
        void deletePeopleById(int);
        void readFile();
        void exportFile();
        ~PEOPLELIST();
};