#include "Date.h"
#include <iomanip>

DATE::DATE() {}

DATE::DATE(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    while (!checkDate()) {
        int newDay, newMonth, newYear;
        cout << "Invalid date! Please re-enter day: " ; cin >> newDay;
        cout << "                            month: " ; cin >> newMonth;
        cout << "                            year : " ; cin >> newYear;
        this->day = newDay;
        this->month = newMonth;
        this->year = newYear;
    }
}

void DATE::setDay(int day) {
    this->day = day;
}

int DATE::getDay() {
    return day;
}

void DATE::setMonth(int month) {
    this->month = month;
}

int DATE::getMonth() {
    return month;
}

void DATE::setYear(int year) {
    this->year = year;
}

int DATE::getYear() {
    return year;
}

bool DATE::checkYear() {
    if (year > 0)
        return true;
    return false;
}

bool DATE::checkLeapYear() {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) && checkYear())
        return true;
    return false;
}

bool DATE::checkMonth() {
    if ((month >= 1) && (month <= 12))
        return true;
    return false;
}

int DATE::numDayOfMonth() {
    int numDay;
    switch(month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        numDay = 31;
        break;
    case 4: case 6: case 9: case 11:
        numDay = 30;
        break;
    case 2:
        if (checkLeapYear()) {
            numDay = 29;
        }
        else {
            numDay = 28;
        }
    }
    return numDay;
}
bool DATE::checkDate() {
    if ((checkYear()) && (checkMonth()) && ((day >= 1) && (day <= numDayOfMonth())))
        return true;
    return false;
}

istream& operator>>(istream& in, DATE& date) {
    cout << "\n\n\t\t\t\t\t\t\t\t\t           Enter day  : "; in >> date.day;
    cout << "\n\t\t\t\t\t\t\t\t\t           Enter month: "; in >> date.month;
    cout << "\n\t\t\t\t\t\t\t\t\t           Enter year : "; in >> date.year;
    while (!date.checkDate()) {
        int newDay, newMonth, newYear;
        cout << "\n\t\t\t\t\t\t\t\t\t           INVALID DATE OF BIRTH! PLEASE RE-ENTER IT: " ;
		cout << "\n\n\t\t\t\t\t\t\t\t\t                Enter day  : "; cin >> newDay;
		cout << "\n\t\t\t\t\t\t\t\t\t                Enter month: "; cin >> newMonth;
		cout << "\n\t\t\t\t\t\t\t\t\t                Enter year : "; cin >> newYear;
        date.day = newDay;
        date.month = newMonth;
        date.year = newYear;
    }
    return in;
}

ostream& operator<<(ostream& out, DATE date) {
	if (date.day < 10 && date.month >= 10) {
		out << setw(1) << left << to_string(0) + to_string(date.day) << "/" <<setw(1) << date.month << "/" << setw(4) << left << date.year;
	}
	else if (date.day >= 10 && date.month < 10) {
		out << setw(1) << left << date.day << "/" << setw(1) << to_string(0) + to_string(date.month) << "/" << setw(4) << left << date.year;
	}
	else if (date.day < 10 && date.month < 10 ){
		out << setw(1) << left << to_string(0) + to_string(date.day) << "/" <<setw(1) << to_string(0) + to_string(date.month) << "/" << setw(4) << left << date.year;
	}
	else {
		out << setw(1) << left << date.day << "/" << setw(1) << left << date.month << "/" << setw(4) << left << date.year;
	}
    return out;
}

int DATE::thisIsMagic() {
    if (month < 3) {
        year--;
        month += 12;
	}
    return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}

DATE DATE::aWeekAfter() {
	DATE b = *this;
	b.day = b.day + 7;
	if (b.day > numDayOfMonth()) {
		b.day -= numDayOfMonth();
		b.month = b.month + 1;
		if (b.month > 12) {
			b.month = 1;
			b.year++;
		}
	}
	return b;
}
string DATE::dateString() {
	if (day == 1 || day == 21 || day == 31) {
		return to_string(day) + "st";
	}
	else if (day == 2 || day == 22) {
		return to_string(day) + "nd";
	}
	else if (day == 3 || day == 23) {
		return to_string(day) + "rd";
	}
	else {return to_string(day) + "th";}
}
string DATE::monthString() {
	if (month == 1) {return "January";}
	else if (month == 2) {return "February";}
	else if (month == 3) {return "March";}
	else if (month == 4) {return "April";}
	else if (month == 5) {return "May";}
	else if (month == 6) {return "June";}
	else if (month == 7) {return "July";}
	else if (month == 8) {return "August";}
	else if (month == 9) {return "September";}
	else if (month == 10) {return "October";}
	else if (month == 11) {return "November";}
	else {return "December";}
}
string DATE::printString() {
	return monthString() + " " + dateString() + ", " + to_string(year);
}

void DATE::readFileADate (ifstream &inFile) {
    char x;
    inFile >> this->day;
    inFile >> x;
    inFile >> this->month;
    inFile >> x;
    inFile >> this->year;
    inFile >> x;
}

void DATE::exportFileADate (ofstream &outFile) {
	if (this->day < 10 && this->month >= 10) {
		outFile << setw(1) << left << to_string(0) + to_string(this->day) << "/" <<setw(1) << this->month << "/" << setw(4) << left << this->year;
	}
	else if (this->day >= 10 && this->month < 10) {
		outFile << setw(1) << left << this->day << "/" << setw(1) << to_string(0) + to_string(this->month) << "/" << setw(4) << left << this->year;
	}
	else if (this->day < 10 && this->month < 10 ){
		outFile << setw(1) << left << to_string(0) + to_string(this->day) << "/" <<setw(1) << to_string(0) + to_string(this->month) << "/" << setw(4) << left << this->year;
	}
	else {
		outFile << setw(1) << left << this->day << "/" << setw(1) << left << this->month << "/" << setw(4) << left << this->year;
	}
}

DATE::~DATE() {}

DATE today() {
    int hour, minute, second;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	hour = ltm -> tm_hour;
	minute = ltm -> tm_min;
	second = ltm -> tm_sec;
	DATE today;
	today.setYear(1900 + ltm -> tm_year);
	today.setMonth(1 + ltm -> tm_mon);
	today.setDay(ltm -> tm_mday);
	return today;
}