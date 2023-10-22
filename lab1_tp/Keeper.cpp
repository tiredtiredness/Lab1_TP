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

void Keeper::edit() {
    int index;
    if (!size) {
        cout << "Контейнер пуст" << endl;
        return;
    }
    try {
        for (int i = 0; i < size; i++) {
            cout << "(" << i << ")";
            switch (data[i]->getType()) {
                case 1:
                    cout << "Самолет" << endl;
                    break;
                case 2:
                    cout << "Поезд" << endl;
                    break;
                case 3:
                    cout << "Автомобиль" << endl;
                    break;
                default:
                    break;
            }
        }
        cout << "Выберите элемент для изменения";
        cin >> index;
        if (index < 0 || index > size - 1) {
            throw "Неверный индекс";
        }
        data[index]->edit();
        if (data[index]->isError()) {
            throw "Возникла ошибка при изменении элемента"
        }
        else {
            cout << "Элемент изменен" << endl;
        }
    }
    catch {
        cout << "Возникла ошибка при изменении элемента" << endl;
    }
}
void Keeper::del() {
    int index;
    if (!size) {
        cout << "Контейнер пуст" << endl;
        return;
    }
    try {
        for (int i = 0; i < size; i++) {
            cout << "(" << i << ")";
            switch (data[i]->getType()) {
                case 1:
                    cout << "Самолет" << endl;
                    break;
                case 2:
                    cout << "Поезд" << endl;
                    break;
                case 3:
                    cout << "Автомобиль" << endl;
                    break;
                default:
                    break;
            }
        }
        cout << "Выберите элемент для удаления";
        cin >> index;
        if (index < 0 || index > size - 1) {
            throw "Неверный индекс";
        }
        if (size == 1) {
            delete[] data;
            data = nullptr;
            cout << "Элемент удален" << endl;
            size--;
            return;
        }
        Carrier** tmp = new Carrier * [size - 1];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (index == i)
                continue;
            tmp[j] = data[i];
        }
        delete[] data;
        data = tmp;
        size--;
        cout << "Элемент удален" << endl;
    }
    catch {
        cout << "Возникла ошибка при удалении элемента" << endl;
    }
}

void Keeper::load() {
    ifstream fin("keeper.txt");
    if (fin.fail()) {
        cout << "Файл пуст" << endl;
        return;
    }
    int type = 0;
    while (fin) {
        fin >> type;
        if (fin.peek() == -1) {
            break;
        }
        add(type, fin);
    }
    fin.close();
    cout << "Элементы загружены из файла" << endl;
}

void Keeper::save() {
    ofstream fout("keeper.txt");
    for (int i = 0; i < size; i++) {
        data[i]->save(fout);
    }
    fout.close();
    cout << "Элементы сохранены в файл" << endl;
}

ostream& operator<<(ostream& out , Keeper& obj) {
    if (!obj.size) {
        cout << "Контейнер пуст" << endl;
        return out;
    }
    for (int i = 0; i < size; i++) {
        obj.data[i]->print(out);
    }
    return out;
}
