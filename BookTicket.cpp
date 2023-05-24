#include "BookTicket.h"

BookTicket::BookTicket(){};
BookTicket::BookTicket(int idBill, string trip, string departure, string detination, string playDay, string playReturn, int quantity, string seatClass, float unitPrice)
{
    this->idBill = idBill;
    this->trip = trip;
    this->departure = departure;
    this->detination = detination;
    this->playDay = playDay;
    this->playReturn = playReturn;
    this->quantity = quantity;
    this->seatClass = seatClass;
    this->unitPrice = unitPrice;
}
void BookTicket::setIdBill(int idBill)
{
    this->idBill = idBill;
}
int BookTicket::getIdBill()
{
    return idBill;
}
void BookTicket::setTrip(string trip)
{
    this->trip = trip;
}
string BookTicket::getTrip()
{
    return trip;
}
void BookTicket::setDeparture(string departure)
{
    this->departure = departure;
}
string BookTicket::getDeparture()
{
    return departure;
}
void BookTicket::setDetination(string)
{
    this->detination = detination;
}
string BookTicket::getDetination()
{
    return detination;
}
void BookTicket::setPlayDay(string)
{
    this->playDay = playDay;
}
string BookTicket::getPlayDay()
{
    return playDay;
}
void BookTicket::setPlayReturn(string playReturn)
{
    this->playReturn = playReturn;
}
string BookTicket::getPlayReturn()
{
    return playReturn;
}
void BookTicket::setQuantity(int quantity)
{
    this->quantity = quantity;
}
int BookTicket::getQuantity()
{
    return quantity;
}
void BookTicket::setUnitPrice(float unitPrice)
{
    this->unitPrice = unitPrice;
}
void BookTicket::setSeatClass(string seatClass)
{
    this->seatClass = seatClass;
}
string BookTicket::getSeatClass()
{
    return seatClass;
}
float BookTicket::getUnitPrice()
{
    return unitPrice;
}
int BookTicket::idTicket()
{
    int ramdom;
    srand(time(0));
    ramdom = rand();
    return ramdom;
}
void BookTicket::readFileBookTicket(ifstream &inFile)
{
    char x;
    inFile >> x;
    inFile >> x;
    getline(inFile, this->trip, ',');
    getline(inFile, this->departure, ',');
    getline(inFile, this->detination, ',');
    inFile >> this->playDay;
    inFile >> this->playReturn;
    inFile >> this->quantity;
    inFile >> x;
    getline(inFile, this->seatClass, ',');
    inFile >> unitPrice;
}
void BookTicket::exportFileBookTicket(ofstream &outFile)
{
    this->idBill = idTicket();
    outFile << endl;
    outFile << this->idBill << ",";
    outFile << this->trip << ",";
    outFile << this->departure << ",";
    outFile << this->detination << ",";
    outFile << this->playDay << ",";
    outFile << this->playReturn << ",";
    outFile << this->quantity << ",";
    outFile << this->seatClass << ",";
    outFile << this->unitPrice << ",";
}

void BookTicket::input()
{
    cout << "\n\nTRIP" << endl;
    cout << "1. One way"
         << "     "
         << "2. Round-trip" << endl;
    int selection;
    cout << "Please enter your selection: ";
    cin >> selection;
    if (selection == 1)
    {
        trip = "One way";
    }
    if (selection == 2)
    {
        trip = "Round-trip";
    }
    cin.ignore();
    cout << "Point of departure: ";
    getline(cin, departure);
    cout << "Destination: ";
    getline(cin, detination);
    cout << "Date of departure(DD/MM/YYYY): ";
    cin >> playDay;
    // do
    // {
    //     if (ticket.playDay.checkstring() == false)
    //     {
    //         cout << "string FORMAT ERROR!!!\n";
    //         cout << "Re-enter string of departure(DD/MM/YYYY): ";
    //         in >> ticket.playDay;
    //     }
    // } while (ticket.playDay.checkstring() == false);
    if (selection == 2)
    {
        cout << "Date of destination(DD/MM/YYYY): ";
        cin >> playReturn;
        //     do
        // {
        //     if (ticket.playReturn.checkstring() == false)
        //     {
        //         cout << "string FORMAT ERROR!!!\n";
        //         cout << "Re-enter string of destination(DD/MM/YYYY): ";
        //         in >> ticket.playReturn;
        //     }
        // } while (ticket.playDay.checkstring() == false);
    }
    cout << "Number of passengers: ";
    cin >> quantity;
    cout << "Seat class(Trader/Common): ";
    cin >> seatClass;
    cout << "Ticket price: ";
    cin >> unitPrice;
}
void BookTicket::output()
{
    cout << "One way/ Round-trip: " << trip << endl;
    cout << "Point of departure: " << departure << endl;
    cout << "Destination: " << detination << endl;
    cout << "Date of departure(DD/MM/YYYY): " << playDay << endl;
    cout << "Date of destination(DD/MM/YYYY): " << playReturn << endl;
    cout << "Number of passengers: " << quantity << endl;
    cout << "Seat class(Trader/Common): " << seatClass << endl;
    cout << "Ticket price: " << unitPrice << endl;
}
BookTicket::~BookTicket() {}