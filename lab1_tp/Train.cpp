#include "Train.hpp"
#include <string>

Train::Train() {
    cout << "Добавление поезда" << endl;
    try {
        setType(2);
        cout << "Введите название поезда" << endl;
        cin >> name;
        if (name == "") {
            cout << "Название поезда не может быть пустым" << endl;
        }
        cout << "Введите год выпуска поезда" << endl;
        cin >> this->year;
        if (!this->year || this->year < 0) {
            cout << "Неверное значение года выпуска" << endl;
        }
        cout << "Введите маршрут следования поезда" << endl;
        cin >> route;
        if (route == "") {
            cout << "Маршрут следования не может быть пустым" << endl;
        }
        cout << "Введите количество вагонов" << endl;
        cin >> this->wagonsCount;
        if (!this->wagonsCount || this->wagonsCount < 0) {
            cout << "Неверное значение количества вагонов" << endl;
        }
        cout << "Введите объем перевозимого груза" << endl;
        cin >> this->volume;
        if (!this->volume || this->volume < 0) {
            cout << "Неверное значение объема" << endl;
        }
        setError(false);
    }
    catch (string err) {
        cout << "Возникла ошибка" << err << endl;
        setError(true);
    }
}

Train::Train(ifstream& fin) {
    setType(2);
    fin >> this->name >> this->year >> this->route >> this->wagonsCount >> this->volume;
}

Train::~Train() {}

void Train::edit() {
    try {
        int index;
        int iTmp;
        string sTmp;
        cout << "Выберите параметр для изменения:" << endl
            << "(1) Название" << endl
            << "(2) Год выпуска" << endl
            << "(3) Маршрут" << endl
            << "(4) Количество вагонов" << endl
            << "(5) Объем перевозимого груза" << endl
            << "Выбор: ";
        cin >> index;
        if (index < 1 || index > 5) {
            throw "Неверное значение индекса";
        }
        cout << "Исходное значение: ";
        switch (index) {
            case 1:
                cout << name << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                name = sTmp;
                break;
            case 2:
                cout << year << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                year = iTmp;
                break;
            case 3:
                cout << route << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                route = sTmp;
                break;
            case 4:
                cout << wagonsCount << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                wagonsCount = iTmp;
                break;
            case 5:
                cout << volume << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                volume = iTmp;
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

void Train::save(ofstream &fout)  {
    fout << getType() << endl
        << this->name << endl
        << this->year << endl
        << this->route << endl
        << this->wagonsCount << endl
    << this->volume << endl;
}

void Train::print(ostream& out) {
    out << "Поезд" << endl
        << "Название: " << this->name<< endl
        << "Год выпуска: " << this->year<< endl
        << "Маршрут: " << this->route << endl
        << "Количество вагонов: " << this->wagonsCount << endl
    << "Объем груза: " << this->volume << endl;
}
