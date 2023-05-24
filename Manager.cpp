#include "Manager.h"
Manager::Manager()
{
}
Manager::Manager(string ID, string name, string sex, int age, string phone, string email, string address) : People(ID, name, sex, age, phone, email, address)
{
}
void Manager::readFilePeople(ifstream &inFile)
{
    char x;
    inFile >> x;
    getline(inFile, this->ID, ',');
    getline(inFile, this->name, ',');
    getline(inFile, this->sex, ',');
    inFile >> this->age;
    inFile >> x;
    getline(inFile, this->phone, ',');
    getline(inFile, this->email, ',');
    getline(inFile, this->address, ',');
}
void Manager::exportFilePeople(ofstream &outFile)
{
    outFile << 1 << ",";
    outFile << this->ID << ",";
    outFile << this->name << ",";
    outFile << this->sex << ",";
    outFile << this->age << ",";
    outFile << this->phone << ",";
    outFile << this->email << ",";
    outFile << this->address << ",";
}
void Manager::input()
{
    cin.ignore();
    cout << "Enter Manager ID: ";
    getline(cin, ID);
    cout << "Enter Manager Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter Manager Sex: ";
    cin >> sex;
    cout << "Enter Manager Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Manager Phone: ";
    getline(cin, phone);
    cout << "Enter Manager Email: ";
    cin >> email;
    cout << "Enter Manager Address: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, address);
    cout << "Manager created." << endl;
}
void Manager::output()
{
    cout << "ID :" << ID << endl;
    cout << "Name : " << name << endl;
    cout << "Sex : " << sex << endl;
    cout << "Age : " << age << endl;
    cout << "Phone : " << phone << endl;
    cout << "Email : " << email << endl;
    cout << "Adress : " << address << endl;
}
Manager::~Manager() {}