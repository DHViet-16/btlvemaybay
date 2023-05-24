#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
class BookTicket
{
private:
    int idBill;
    string trip;
    int quantity;
    float unitPrice;
    string departure;
    string detination;
    string playDay;
    string playReturn;
    string seatClass;

public:
    BookTicket();
    BookTicket( int, string, string, string, string, string, int, string, float);
    void setIdBill(int);
    int getIdBill();
    void setTrip(string);
    string getTrip();
    void setDeparture(string);
    string getDeparture();
    void setDetination(string);
    string getDetination();
    void setPlayDay(string);
    string getPlayDay();
    void setPlayReturn(string);
    string getPlayReturn();
    void setQuantity(int);
    int getQuantity();
    void setSeatClass(string);
    string getSeatClass();
    void setUnitPrice(float);
    float getUnitPrice();
    int idTicket();
    void input();
    void output();
    void readFileBookTicket(ifstream &);
    void exportFileBookTicket(ofstream &);
    ~BookTicket();
};