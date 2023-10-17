#include <string>

class Plane {
private:
    int year;
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
