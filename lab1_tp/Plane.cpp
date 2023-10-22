#include "Plane.hpp"
#include <string>

Plane::Plane() {
    cout << "Добавление самолета" << endl;
    try {
        setType(1);
        cout << "Введите тип самолета" << endl;
        cin >> this->type;
        if (type == "") {
            cout << "Тип самолета не может быть пустым" << endl;
        }
        setError(false);
        cout << "Введите название самолета" << endl;
        cin >> this->name;
        if (name == "") {
            cout << "Название самолета не может быть пустым" << endl;
        }
        cout << "Введите объем перевозимого груза" << endl;
        cin >> this->volume;
        if (!this->volume || this->volume < 0) {
            cout << "Неверное значение объема перевозимого груза" << endl;
        }
        cout << "Введите габариты самолета" << endl;
        cin >> this->size;
        if (!this->size || this->size < 0) {
            cout << "Неверное значение габоритов" << endl;
        }
        cout << "Города, в которые летает самолет" << endl;
        cin >> this->city;
        if (city == "") {
            cout << "Названия не могут быть пустыми" << endl;
        }
        setError(false);
    }
    catch (string err) {
        cout << "Возникла ошибка" << err << endl;
        setError(true);
    }
}

Plane::Plane(ifstream& fin) {
    setType(1);
    fin >> this->type >> this->name >> this->volume >> this->size >> this->city;
}

Plane::~Plane() {}

void Plane::edit() {
    try {
        int index;
        int iTmp;
        string sTmp;
        cout << "Выберите параметр для изменения:" << endl
            << "(1) Тип" << endl
            << "(2) Название" << endl
            << "(3) Объем перевозимого груза" << endl
            << "(4) Габариты" << endl
            << "(5) Города" << endl
            << "Выбор: ";
        cin >> index;
        if (index < 1 || index > 5) {
            throw "Неверное значение индекса";
        }
        cout << "Исходное значение: ";
        switch (index) {
            case 1:
                cout << type << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                type = sTmp;
                break;
            case 2:
                cout << name << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                name = sTmp;
                break;
            case 3:
                cout << volume << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                volume = iTmp;
                break;
            case 4:
                cout << size << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                size = iTmp;
                break;
            case 5:
                cout << city << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                city = sTmp;
                break;
            default:
                break;
        }
        setError(false);
    }
    catch (string err) {
        cout << err << endl;
        setError(true);
    }
}

void Plane::save(ofstream &fout)  {
    fout << getType() << endl
        << this->type << endl
        << this->name << endl
        << this->volume << endl
        << this->size << endl
        << this->city << endl;
}

void Plane::print(ostream& out) {
    out << "Самолет" << endl
        << "Тип: " << this->type<< endl
        << "Название: " << this->name<< endl
        << "Объем перевозимого груза: " << this->volume << endl
        << "Габариты: " << this->size << endl
        << "Города: " << this->city << endl;
}
