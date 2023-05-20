#pragma once
#include "ACCOUNT.h"

class USER : public ACCOUNT
{
    private:
        string idUser;
    public:
        USER();
        USER(string, string, string);
        void setIdUser(string);
        string getIdUser();
        string getId();
        int getFormat();
        void input(int);
        void readFileAAccount(ifstream &);
        void exportFileAAccount(ofstream &);
        void changePassword(string _password);
        void changeUserName(string _userName);
        ~USER();
};