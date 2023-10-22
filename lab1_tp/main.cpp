#include <iostream>
#include "Keeper.hpp"
#include <string>

using namespace std;

int main() {
    Keeper keeper;
    int choice;
    while (true) {
        cout << "Меню" << endl
        << "Кол-во элементов в контейнере: " << "" << endl
        << "(1) Добавить элемент" << endl
        << "(2) Удалить элемент" << endl
        << "(3) Сохранить данные в файл" << endl
        << "(4) Загрузить данные из файла" << endl
        << "(5) Изменить данные элемента" << endl
        << "(6) Вывести данные из контейнера" << endl
        << "(0) Выход" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                keeper.add();
                break;
            case 2:
                keeper.del();
                break;
            case 3:
                keeper.save();
                break;
            case 4:
                keeper.load();
                break;
            case 5:
                keeper.edit();
                break;
            case 6:
                cout << keeper;
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
}
