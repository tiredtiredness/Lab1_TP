#pragma once
#include "CargoCarrier.hpp"
#include <string>

using namespace std;

class Car : public CargoCarrier {
private:
    int year;
    string brand;
    string model;
    string city;
    string deliveryTime;
    float volume;
public:
    Car();
    Car(ifstream& fin);
    ~Car();
    void edit();
    void save(ofstream& fout);
    void print(ostream& out);
};
