#pragma once
#include "CargoCarrier.hpp"
#include <string>

using namespace std;

class Plane : public CargoCarrier {
private:
    string type;
    string name;
    float volume;
    float size;
    string city;
public:
    Plane();
    Plane(ifstream& fin);
    ~Plane();
    void edit();
    void save(ofstream& fout);
    void print(ostream& out);
};
