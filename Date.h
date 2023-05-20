#pragma once
#include <iostream>
#include <cstring>
#include <time.h>
#include <fstream>

using namespace std;

class DATE {
    private:
        int day, month, year;
    public:
        DATE();
        DATE(int, int, int);
        void setDay(int);
        int getDay();
        void setMonth(int);
        int getMonth();
        void setYear(int);
        int getYear();
        bool checkYear();
        bool checkLeapYear();
        bool checkMonth();
        int numDayOfMonth();
        bool checkDate();
        friend istream& operator>>(istream&, DATE&);
        friend ostream& operator<<(ostream&, DATE);
        int thisIsMagic();
        string dateString();
        string monthString();
        string printString();
        DATE aWeekAfter();
        void readFileADate(ifstream &inFile);
        void exportFileADate (ofstream &outFile);
        ~DATE();
};

DATE today();