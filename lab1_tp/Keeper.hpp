#include "CargoCarrier.hpp"
#include "Plane.hpp"
#include "Train.hpp"
#include "Car.hpp"
#include <fstream>

class Keeper {
private:
    CargoCarrier** data;
    int size;
public:
    Keeper();
    ~Keeper();
    int getSize();
    void add();
    void add(int type, ifstream& fin);
    void del();
    void edit();
    void save();
    void load();
    friend ostream& operator<<(ostream& out, Keeper& obj);
};
