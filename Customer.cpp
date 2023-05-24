#include "Customer.h"
Customer::Customer()
{
}
Customer::Customer(string ID, string name, string sex, int age, string phone, string email, string address) : People(ID, name, sex, age, phone, email, address)
{
}
void Customer::readFilePeople(ifstream &inFile)
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
void Customer::exportFilePeople(ofstream &outFile)
{
    outFile << 2 << ",";
    outFile << this->ID << ",";
    outFile << this->name << ",";
    outFile << this->sex << ",";
    outFile << this->age << ",";
    outFile << this->phone << ",";
    outFile << this->email << ",";
    outFile << this->address << ",";
}
void Customer::input()
{
    cin.ignore();
    cout << "Enter Customer ID: ";
    getline(cin, ID);
    cout << "Enter Customer Name: ";
    getline(cin, name);
    cout << "Enter Customer Sex: ";
    cin >> sex;
    cout << "Enter Customer Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Customer Phone: ";
    getline(cin, phone);
    cout << "Enter Customer Email: ";
    getline(cin, email);
    cout << "Enter Customer Address: ";
    getline(cin, address);
    cout << "Customer created." << endl;
}
void Customer::output()
{
    cout << "ID :" << ID << endl;
    cout << "Name : " << name << endl;
    cout << "Sex : " << sex << endl;
    cout << "Age : " << age << endl;
    cout << "Phone : " << phone << endl;
    cout << "Email : " << email << endl;
    cout << "Adress : " << address << endl;
}
Customer::~Customer(){}