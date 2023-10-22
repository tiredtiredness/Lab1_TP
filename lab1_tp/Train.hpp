#pragma once
#include "CargoCarrier.hpp"
#include <string>

using namespace std;

class Train : public CargoCarrier {
private:
    string name;
    int year;
    string route;
    int wagonsCount;
    int volume;
public:
    Train();
    Train(ifstream& fin);
    ~Train();
    void edit();
    void save(ofstream& fout);
    void print(ostream& out);
};
