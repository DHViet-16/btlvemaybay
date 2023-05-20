#include "People.h"
#include <vector>

class Manager: public People
{
    public:
    Manager();
    Manager(int , string ,string ,int , int,  string , string );
    void input();
    void output();
    void readFilePeople(ifstream &inFile);
    void exportFilePeople (ofstream &outFile);
    ~Manager();
};