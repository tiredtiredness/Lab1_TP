#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CargoCarrier {
private:
    int type;
    bool error;
public:
    void setType(int type);
    int getType();
    bool isError();
    virtual void save(ofstream& fout) = 0;
    virtual void edit() = 0;
    virtual void print(ostream& out) = 0;
    virtual ~CargoCarrier() = 0;
};
