#include "Admin.h"

ADMIN::ADMIN() {}

ADMIN::ADMIN(string username, string password, string idAdmin) : ACCOUNT(username, password) {
    this->idAdmin = idAdmin;
}

void ADMIN::setIdAdmin(string idAdmin) {
    this->idAdmin = idAdmin;
}

string ADMIN::getId() {
    return this->idAdmin;
}

string ADMIN::getIdAdmin() {
    return idAdmin;
}

int ADMIN::getFormat() {
    return 1;
}

void ADMIN::input(int idAdmin) {
//    cin.ignore();
    char ch;
    cout << "\n\t\t\t\t\t\t\t\t\t      Enter username                : ";
	getline(cin, username);
	string pass, comfirmPass;
	cout << "\n\t\t\t\t\t\t\t\t\t      Enter password                : ";
	ch = getch();
    while (ch != 13) {
        if(ch != 8) {
            pass.push_back(ch);
            cout << '*';
        }
        else {
            if(pass.size() != 0) {
                pass.erase(pass.end() - 1);
                cout << "\b \b";
            }
        }
        ch = getch();
    }
    cout << "\n\n\t\t\t\t\t\t\t\t\t      Re-Enter password to comfirm  : ";
    ch = getch();
    while (ch != 13) {
        if(ch != 8) {
            comfirmPass.push_back(ch);
            cout << '*';
        }
        else {
            if(comfirmPass.size() != 0) {
                comfirmPass.erase(comfirmPass.end() - 1);
                cout << "\b \b";
            }
        }
        ch = getch();
    }
    do {
        if (comfirmPass != pass) {
            cout << "\n\n\t\t\t\t\t\t\t\t\t                          INCORRECT PASSWORD!";
            cout << "\n\n\t\t\t\t\t\t\t\t\t                  Please re-enter your password to comfirm : ";
            comfirmPass.clear();
            ch = getch();
            while (ch != 13) {
                if(ch != 8) {
                    comfirmPass.push_back(ch);
                    cout << '*';
                }
                else {
                    if(comfirmPass.size() != 0) {
                        comfirmPass.erase(comfirmPass.end() - 1);
                        cout << "\b \b";
                    }
                }
                ch = getch();
            }
        }
    } while (comfirmPass != pass);
    this->password = pass;
	this->idAdmin = idAdmin;
}

void ADMIN::readFileAAccount(ifstream &inFile) {
    char x;
    inFile >> x;
    getline(inFile, this->username, ',');
    getline(inFile, this->password, ',');
    getline(inFile, this->idAdmin, ',');
}

void ADMIN::exportFileAAccount(ofstream &outFile) {
    outFile << 1 << ",";
    outFile << this->username << ",";
    outFile << this->password << ",";
    outFile << this->idAdmin << ",";
}

void ADMIN::changePassword(string password) {
    this -> password = password;
}

void ADMIN::changeUserName(string username) {
    this -> username = username;
}

ADMIN::~ADMIN(){}