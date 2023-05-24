#include <iostream>
#include <vector>
#include <string.h>
#include "AccountList.h"
#include "Admin.h"
#include "User.h"
#include "PeopleList.h"
#include "BookTicketList.h"

ACCOUNTSLIST accountsList;
PEOPLELIST PeopleList;
BookTicketList bookticketslist;

using namespace std;

void standardizeName(string &s)
{
    int n = s.length();
    // Xóa khoảng trắng đầu và cuối xâu
    while (s[0] == ' ')
    {
        s.erase(s.begin() + 0); // Xoa ki tu tai vi tri 0
    }
    while (s[n - 1] == ' ')
    {
        s.erase(s.begin() + (n - 1)); // Xoa ki tu tai vi tri cuoi
    }
    // xoa khoang trang thua o giua cac tu
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    // viet hoa moi ki tu dau
    strlwr((char *)s.c_str()); // chuyen ve chuoi in thuong
    s[0] = s[0] - 32;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            s[i + 1] = s[i + 1] - 32;
        }
    }
}
void showMainMenuAdmin()
{
    system("cls");
    cout << "1. Output All Ticket"
         << "    "
         << "2. Change your user name"
         << "    "
         << "3. Change your password"
         << endl
         << endl
         << "Press 000 to log out" << endl;
}
void showMainMenuUser()
{
    system("cls");
    cout << "1. Output your information"
         << "    "
         << "2. Change your user name"
         << "    "
         << "3. Change your password"
         << "    " << endl;
    cout << " 4.Book Ticket"
         << "    "
         << "5. Check your ticket "
         << endl
         << endl
         << "Press 000 to log out" << endl;
}
void showExitMenu()
{
    cout << "\n";
    cout << "\tHAVE A GREAT WORKING DAY";
    cout << "\n THANK YOU AND SEE YOU SOON"<<endl;
}
void menuAdmin(int index)
{
    while (true)
    {
        showMainMenuAdmin();
        int selection;
        cout << "\n PLEASE ENTER YOUR SELECTION: ";
        cin >> selection;
        cin.ignore();
        if (selection == 1)
        {
        }
        if (selection == 2)
        {
            system("cls");
            cout << "\n[ANNOUNCEMENT] YOU HAVE CHOSE OPTION 2 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n       Enter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountsList.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n DUPLICATED USER NAME ERROR!";
                    cout << "\n Please re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountsList.checkDuplicatedUsername(newUserName) == true);
            accountsList.getAccountsList()[index]->changeUserName(newUserName);
            accountsList.exportFile();
            cout << "\nChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 3)
        {
            system("cls");
            cout << "\n[ANNOUNCEMENT] YOU HAVE CHOSE OPTION 3 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n Enter your old password: ";
            cin >> oldPassword;
            if (accountsList.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\nINCORRECT PASSWORD!";
                cout << "\nPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\nEnter your new password: ";
            cin >> newPassword;
            if (accountsList.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\nNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\nPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountsList.getAccountsList()[index]->changePassword(newPassword);
            accountsList.exportFile();
            cout << "\nChange password successfully! Press any key to continue. . .";
        }
        if (selection == 000)
        {
            cout << "\n Do you want to log out? [Yes/No]: ";
            string answer;
            getline(cin, answer);
            standardizeName(answer);
            if (answer == "Yes")
            {
                showExitMenu();
                break;
            }
        }
    }
}
void menuUser(int index)
{
    while (true)
    {
        showMainMenuUser();
        int selection;
        cout << "\n PLEASE ENTER YOUR SELECTION: ";
        cin >> selection;
        cin.ignore();
        if (selection == 1)
        {
            PeopleList.getPeopleList()[PeopleList.findPeopleById(accountsList.getAccountsList()[index]->getId())]->output();
            cout << "Press any key to return to MENU . . .";
            getch();
        }
        if (selection == 2)
        {
            system("cls");
            cout << "\n[ANNOUNCEMENT] YOU HAVE CHOSE OPTION 2 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n       Enter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountsList.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n DUPLICATED USER NAME ERROR!";
                    cout << "\n Please re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountsList.checkDuplicatedUsername(newUserName) == true);
            accountsList.getAccountsList()[index]->changeUserName(newUserName);
            accountsList.exportFile();
            cout << "\nChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 3)
        {
            system("cls");
            cout << "\n[ANNOUNCEMENT] YOU HAVE CHOSE OPTION 3 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n Enter your old password: ";
            cin >> oldPassword;
            if (accountsList.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\nINCORRECT PASSWORD!";
                cout << "\nPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\nEnter your new password: ";
            cin >> newPassword;
            if (accountsList.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\nNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\nPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountsList.getAccountsList()[index]->changePassword(newPassword);
            accountsList.exportFile();
            cout << "\nChange password successfully! Press any key to continue. . .";
             getch();
            break;
        }
        if (selection == 4)
        {
            bookticketslist.input();
            bookticketslist.exportFIle();
        }
        if (selection == 5)
        {
            bookticketslist.output();
        }
        if (selection == 000)
        {
            cout << "\n Do you want to log out? [Yes/No]: ";
            string answer;
            getline(cin, answer);
            standardizeName(answer);
            if (answer == "Yes")
            {
                showExitMenu();
                break;
            }
        }
    }
}
int passAccount()
{
    string username, password;
    cout << "\n  Enter your username: ";
    cin >> username;
    cout << "\n Enter your password: ";
    cin >> password;
    if (accountsList.checkAccount(username, password) != -1)
        return accountsList.checkAccount(username, password);
    return -1;
}
void signup()
{
    PeopleList.input(accountsList);
    PeopleList.exportFile();
    accountsList.exportFile();
}
int main()
{
    //bookticketslist.readFile();
    PeopleList.readFile();
    accountsList.readFile();

    while (true)
    {
        system("cls");
        cout << "1. LOGIN"
             << "               "
             << "2. SIGN UP" << endl;
        int option;
        cout << "PLEASE ENTER YOUR OPTION: ";
        cin >> option;
        if (option == 2)
        {
            signup();
        }
        system("cls");
        int index = passAccount();
        if (index != -1)
        {
            cout << "\n [ANNOUNCEMENT] Login successfully! Press any key to continue!";
            if (accountsList.getAccountsList()[index]->getFormat() == 1)
            {
                menuAdmin(index);
                //                system("pause");
            }
            else
            {
                menuUser(index);
            }
        }
        else
        {
            cout << "\n YOUR ACCOUNT ISN'T EXISTING! PLEASE CONTACT ADMINISTRATOR TO CREATE AN ACOUNT NOW!\n [ANNOUNCEMENT] ";
            system("pause");
        }
    }
    return 0;
}
