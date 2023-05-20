#include <iostream>
#include <vector>
#include <string.h>
#include "Account.h"
#include "AccountList.h"
#include "Admin.h"
#include "User.h"

ACCOUNTSLIST accountlist;
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
         << "    "<<endl
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
            "    "<<endl
         << "Press 000 to log out" << endl;
}
void showExitMenu()
{
    cout << "\n";
    cout << "\tHAVE A GREAT WORKING DAY";
    cout << "\n THANK YOU AND SEE YOU SOON";
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
                if (accountlist.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n DUPLICATED USER NAME ERROR!";
                    cout << "\n Please re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountlist.checkDuplicatedUsername(newUserName) == true);
            accountlist.getAccountsList()[index]->changeUserName(newUserName);
            accountlist.exportFile();
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
            if (accountlist.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\nINCORRECT PASSWORD!";
                cout << "\nPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\nEnter your new password: ";
            cin >> newPassword;
            if (accountlist.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\nNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\nPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountlist.getAccountsList()[index]->changePassword(newPassword);
            accountlist.exportFile();
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
        }
        if (selection == 2)
        {
            system("cls");
            cout << "\n[ANNOUNCEMENT] YOU HAVE CHOSE OPTION 26 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n       Enter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountlist.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n DUPLICATED USER NAME ERROR!";
                    cout << "\n Please re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountlist.checkDuplicatedUsername(newUserName) == true);
            accountlist.getAccountsList()[index]->changeUserName(newUserName);
            accountlist.exportFile();
            cout << "\nChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 3)
        {
            system("cls");
            cout << "\n[ANNOUNCEMENT] YOU HAVE CHOSE OPTION 27 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n Enter your old password: ";
            cin >> oldPassword;
            if (accountlist.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\nINCORRECT PASSWORD!";
                cout << "\nPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\nEnter your new password: ";
            cin >> newPassword;
            if (accountlist.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\nNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\nPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountlist.getAccountsList()[index]->changePassword(newPassword);
            accountlist.exportFile();
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
int passAccount()
{
    string username, password;
    cout << "LOGIN" << endl;
    cout << "\n  Enter your username: ";
    cin >> username;
    cout << "\n Enter your password:";
    cin >> password;
    if (accountlist.checkAccount(username, password) != -1)
        return accountlist.checkAccount(username, password);
    return -1;
}
int main()
{
    accountlist.readFile();
    while (true)
    {
        system("cls");
        int index = passAccount();
        if (index != -1)
        {
            cout << "\n [ANNOUNCEMENT] Login successfully! Press any key to continue!";
            if (accountlist.getAccountsList()[index]->getFormat() == 1)
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
