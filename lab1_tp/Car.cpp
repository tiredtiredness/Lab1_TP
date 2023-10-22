#include "Car.hpp"
#include <string>

Car::Car() {
    cout << "Добавление самолета" << endl;
    try {
        setType(3);
        cout << "Введите год выпуска автомобиля" << endl;
        cin >> this->year;
        if (!this->year || this->year < 0) {
            cout << "Неверное значение года выпуска" << endl;
        }
        setError(false);
        cout << "Введите марку автомобиля" << endl;
        cin >> this->brand;
        if (brand == "") {
            cout << "Марка не может быть пустой" << endl;
        }
        cout << "Введите модель автомобиля" << endl;
        cin >> this->model;
        if (model == "") {
            cout << "Модель не может быть пустой" << endl;
        }
        cout << "Введите город доставки" << endl;
        cin >> this->city;
        if (city == "") {
            cout << "Город не может быть пустым" << endl;
        }
        cout << "Введите время доставки" << endl;
        cin >> this->deliveryTime;
        if (deliveryTime == "") {
            cout << "Неверное значение времени доставки" << endl;
        }
        cout << "Введите объем перевозимого груза" << endl;
        cin >> this->volume;
        if (!this->volume || this->volume < 0) {
            cout << "Неверное значение объема перевозимого груза" << endl;
        }
        setError(false);
    }
    catch (string err) {
        cout << "Возникла ошибка" << err << endl;
        setError(true);
    }
}

Car::Car(ifstream& fin) {
    setType(3);
    fin >> this->year >> this->brand >> this->model >> this->city >> this->deliveryTime >> this->volume;
}

Car::~Car() {}

void Car::edit() {
    try {
        int index;
        int iTmp;
        string sTmp;
        cout << "Выберите параметр для изменения:" << endl
            << "(1) Год выпуска" << endl
            << "(2) Марка" << endl
            << "(3) Модель" << endl
            << "(4) Город доставки" << endl
            << "(5) Время доставки" << endl
            << "(6) Объем груза" << endl
            << "Выбор: ";
        cin >> index;
        if (index < 1 || index > 5) {
            throw "Неверное значение индекса";
        }
        cout << "Исходное значение: ";
        switch (index) {
            case 1:
                cout << year << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                year = iTmp;
                break;
            case 2:
                cout << brand << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                brand = sTmp;
                break;
            case 3:
                cout << model << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                model = sTmp;
                break;
            case 4:
                cout << city << endl;
                cout << "Новое значение: ";
                cin >> sTmp;
                if (sTmp == "")
                    throw "Значение не может быть пустым";
                city = sTmp;
                break;
            case 5:
                cout << deliveryTime << endl;
                cout << "Новое значение: ";
                cin >> iTmp;
                if (iTmp < 0)
                    throw "Значение не может быть больше или равно 0";
                deliveryTime = iTmp;
                break;
            case 6:
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

void Car::save(ofstream &fout)  {
    fout << getType() << endl
        << this->year << endl
        << this->brand << endl
        << this->model << endl
        << this->city << endl
        << this->deliveryTime << endl
        << this->volume << endl;
}

void Car::print(ostream& out) {
    out << "Автомобиль" << endl
        << "Год выпуска: " << this->year<< endl
        << "Марка: " << this->brand<< endl
        << "Модель: " << this->model<< endl
        << "Город доставки: " << this->city << endl
        << "Время доставки: " << this->deliveryTime << endl
        << "Объем груза: " << this->volume << endl;
}
