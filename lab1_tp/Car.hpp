#include <string>

class Car {
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
