#include "Customer.h"
Customer::Customer()
{
}
Customer::Customer(int ID, string name, string sex, int age, int phone, string email, string address) : People(ID, name, sex, age, phone, email, address)
{
}
void Customer::readFilePeople(ifstream &inFile)
{
    inFile >> this->ID;
    getline(inFile, this->name, ',');
    getline(inFile, this->sex, ',');
    inFile >> this->age;
    inFile >> this->phone;
    getline(inFile, this->email, ',');
    getline(inFile, this->address, ',');
}
void Customer::exportFilePeople(ofstream &outFile)
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
void Customer::input()
{
    cout << "Enter Customer ID: ";
    cin >> ID;
    cout << "Enter Customer Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter Customer Sex: ";
    cin >> sex;
    cout << "Enter Customer Phone: ";
    cin >> phone;
    cout << "Enter Customer Email: ";
    cin >> email;
    cout << "Enter Customer Address: ";
    cin.ignore(); // Clear the input buffer
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