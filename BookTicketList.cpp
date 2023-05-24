#include "BookTicketList.h"

BookTicketList::BookTicketList()
{
}
void BookTicketList::readFile()
{
    ifstream inFile;
    inFile.open("Data Book Ticket.txt", ios::in);
    while (!inFile.eof())
    {
        BookTicket temp;
        temp.readFileBookTicket(inFile);
        bookticketslist.push_back(temp);
        inFile.ignore();
        if (inFile.eof())
        {
            break;
        }
    }
    inFile.close();
}
void BookTicketList::exportFIle()
{
    ofstream outFile;
    outFile.open("Data Book Ticket.txt",ios::app);
    for (int i = 0; i < bookticketslist.size(); i++)
    {
        if (i != bookticketslist.size() - 1)
        {
            bookticketslist[i].exportFileBookTicket(outFile);
            outFile << endl;
        }
        else
        {
            bookticketslist[i].exportFileBookTicket(outFile);
        }
    }
    outFile.close();
}
void BookTicketList::setBookTicketList(vector<BookTicket> bookticketslist)
{
    this->bookticketslist = bookticketslist;
}
vector<BookTicket> BookTicketList::getBookTicketList()
{
    return bookticketslist;
}
void BookTicketList::input()
{
    BookTicket Temporary;
    Temporary.input();
    bookticketslist.push_back(Temporary);
}
void BookTicketList::output()
{
    for (int i = 0; i < bookticketslist.size(); i++)
    {
        bookticketslist[i].output();
    }
}
BookTicketList::~BookTicketList() {}