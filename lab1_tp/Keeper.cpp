#include "Keeper.hpp"

Keeper::Keeper() {
    this->data = nullptr;
    this->size = 0;
}

Keeper::~Keeper() {
    delete[] data;
}

int Keeper::getSize() {
    return size;
}

void Keeper::add() {
    int type;
    try {
        cout << "Выберите класс наследника:" << endl
            << "(1) Самолет" << endl
            << "(1) Поезд" << endl
            << "(1) Автомобиль" << endl
            << "Ваш выбор: ";
        cin >> type;
        if (type > 3 || type < 1) {
            throw "Неверный класс наследника"
        }
        CargoCarrier** tmp = new CargoCarrier * [size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i];
        }
        switch (type) {
            case 1:
                tmp[size] = new Airplane;
                break;
            case 2:
                tmp[size] = new Train;
                break;
            case 3:
                tmp[size] = new Car;
                break;
            default:
                break;
        }
        if (tmp[size]->isError()) {
            cout << "Возникла ошибка при добавлении элемента" << endl;
            return;
        }
        size++;
        if (data) {
            delete[] data;
        }
        data = tmp;
        cout << "Элемент успешно добавлен" << endl;
    }
    catch {
        cout << err << endl;
    }
}
