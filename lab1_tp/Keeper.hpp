#include "Plane.hpp"
#include "Train.hpp"
#include "Car.hpp"

class Keeper {
private:
    CargoCarrier** data;
    int size;
public:
    Keeper();
    ~Keeper();
    int getSize();
    void add();
    void del();
    void edit();
    void save();
    void load();
};
