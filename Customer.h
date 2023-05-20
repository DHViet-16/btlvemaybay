#include "People.h"
#include <vector>

class Customer: public People
{
    public:
    Customer();
    Customer(int , string ,string ,int , int,  string , string );
    void input();
    void output();
    void readFilePeople(ifstream &inFile);
    void exportFilePeople (ofstream &outFile);
    ~Customer();
};