#include "User.h"

USER::USER() {}

USER::USER(string username, string password, string idUser) : ACCOUNT(username, password) {
    this->idUser = idUser;
}

void USER::setIdUser(string idUser) {
    this->idUser = idUser;
}

string USER::getIdUser() {
    return idUser;
}

int USER::getFormat() {
    return 2;
}

void USER::input(int iduser) {
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
	this->idUser = idUser;
}

string USER::getId () {
    return this->idUser;
}

void USER::readFileAAccount(ifstream &inFile) {
    char x;
    inFile >> x;
    getline(inFile, this->username, ',');
    getline(inFile, this->password, ',');
    getline(inFile, this->idUser, ',');
}

void USER::exportFileAAccount(ofstream &outFile) {
    outFile << 2 << ",";
    outFile << this->username << ",";
    outFile << this->password << ",";
    outFile << this->idUser << ",";
}
void USER::changePassword(string _password) {
    this -> password = _password;
}
void USER::changeUserName(string _userName) {
    this -> username = _userName;
}
USER::~USER() {}