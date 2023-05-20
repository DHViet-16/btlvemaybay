#include "PeopleList.h"
PEOPLELIST::PEOPLELIST() {}
void PEOPLELIST::setPeopleList(vector<People *> PeopleList)
{
    this->PeopleList = PeopleList;
}
vector<People *> PEOPLELIST::getPeopleList()
{
    return this->PeopleList;
}
void PEOPLELIST::input(ACCOUNTSLIST &accountsList)
{
    int quantities;
    cout << "\n Number of readers you want to add is: ";
    cin >> quantities;
    cin.ignore();
    for (int i = 0; i < quantities; i++)
    {
        system("cls");
        cout << "INPUT INFORMATION OF THE " << i + 1 << "PEOPLE" << endl;
        int select;
        cout << "\nChoose an option:   " << endl
             << "1. INPUT A CUSTOMER" << endl
             << "2. INPUT A MANAGER" << endl
             << "Your selection is: ";
        cin >> select;
        do
        {
            if (select != 1 && select != 2)
            {
                cout << "\nYOU HAVE ENTERED AN INVALID SELECTION! PLEASE RE-ENTER: ";
                cin >> select;
            }
        } while (select != 1 && select != 2);
        People *Temporary;
        if (select == 1)
        {
            Temporary = new Customer;
        }
        else if (select == 2)
        {
            Temporary = new Manager;
        }
        system("cls");
        cout << "INPUT INFORMATION OF THE " << i + 1 << "PEOPLE" << endl;
        Temporary->input();
        do
        {
            if (checkDuplicatedIdPeople(Temporary->getId()) == true)
            {
                system("cls");
                cout << "INPUT INFORMATION OF THE " << i + 1 << "PEOPLE" << endl;
                cout << "Please re-enter this reader's identification: ";
                int Temp;
                cin >> Temp;
                Temporary->setId(Temp);
            }
        } while (checkDuplicatedIdPeople(Temporary->getId()) == true);
        accountsList.inputAAcount(Temporary->getId());
        PeopleList.push_back(Temporary);
        cout << "\n Input information succesfully!! Press any key to continue. . .";
    }
}
void PEOPLELIST::output()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        cout << "\n Information Of The People" << i + 1 << "\n";
        PeopleList[i]->output();
    }
}
void PEOPLELIST::outputCustomer()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        PeopleList[i]->output();
    }
}
void PEOPLELIST::outputManager()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        PeopleList[i]->output();
    }
}
void PEOPLELIST::outputAllPeople()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        PeopleList[i]->output();
    }
}
bool PEOPLELIST::checkDuplicatedIdPeople(int idpeople)
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (PeopleList[i]->getId() == idpeople)
        {
            return true;
        }
        return false;
    }
}

int PEOPLELIST::findPeopleById(int idpeopele)
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (PeopleList[i]->getId() == idpeopele)
        {
            return i;
        }
    }
    return -1;
}
void PEOPLELIST::findPeopleByName(string name)
{
    bool Check = false;
    for (int i = 0; i < PeopleList.size(); i++)
    {
        string temp = PeopleList[i]->getName();
        if (temp == name)
        {
            cout << "\nFOLLOWING IS ALL THE INFORMATION ABOUT READER YOU ARE LOOKING FOR" << endl;
            PeopleList[i]->output();
            Check = true;
        }
    }
    if (Check == false)
    {
        cout << "\nSORRY!!! THE READER WHOSE INFORMATION YOU ARE LOOKING FOR DOESN'T EXIST!!!";
        cout << "\n PLEASE TRY AGAIN!";
    }
}
void PEOPLELIST::deletePeopleById(int idpeople) {
    for(int i = 0; i < PeopleList.size(); i++) {
        if(PeopleList[i]->getId() == idpeople) {
            PeopleList.erase(PeopleList.begin() + i);
			cout << "\n Delete reader successfully!!! Press any key to continue. . .";
            return;
        }
    }
    cout << "\nNot found this reader!!! Press any key to continue. . .";
}

void PEOPLELIST::readFile()
{
    ifstream inFile;
    inFile.open("Data People.txt", ios::in);
    while (!inFile.eof())
    {
        int select;
        inFile >> select;
        People *Temporary;
        if (select == 1)
        {
            Temporary = new Customer;
        }
        else if (select == 2)
        {
            Temporary = new Manager;
        }
        Temporary->readFilePeople(inFile);
        PeopleList.push_back(Temporary);
        inFile.ignore();
        if (inFile.eof())
        {
            break;
        }
    }
    inFile.close();
}

void PEOPLELIST::exportFile()
{
    ofstream outFile;
    outFile.open("Data People.txt", ios::out);
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (i != PeopleList.size() - 1)
        {
            PeopleList[i]->exportFilePeople(outFile);
            outFile << endl;
        }
        else
        {
            PeopleList[i]->exportFilePeople(outFile);
        }
    }
    outFile.close();
}
PEOPLELIST::~PEOPLELIST() {}
