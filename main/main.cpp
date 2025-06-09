#include <iostream>
#include <string>
#include <vector>
#include "Letnyaya.h"
#include "Zimnyaya.h"
#include "Letnyaya.cpp"
#include "Zimnyaya.cpp"
#include "Odezhda.h"
#include "Odezhda.cpp"

using namespace std;

// Функция для создания летней одежды
Letnyaya* creatOdezhaL() {
    string material;
    double cena;
    string razmer;
    string cvet;
    string ventilatsiya;
    string otkrytost;

    cout << "Введите материал: ";
    cin >> material;
    cout << "Введите цену: ";
    cin >> cena;
    cout << "Введите размер: ";
    cin >> razmer;
    cout << "Введите цвет: ";
    cin >> cvet;
    cout << "Введите вентиляцию: ";
    cin >> ventilatsiya;
    cout << "Введите открытость: ";
    cin >> otkrytost;

    return new Letnyaya(material, cena, razmer, cvet, ventilatsiya, otkrytost);
}

// Функция для создания зимней одежды
Zimnyaya* creatOdezhaZ() {
    string material;
    double cena;
    string razmer;
    string cvet;
    string uteplitel;
    double plotnost;

    cout << "Введите материал: ";
    cin >> material;
    cout << "Введите цену: ";
    cin >> cena;
    cout << "Введите размер: ";
    cin >> razmer;
    cout << "Введите цвет: ";
    cin >> cvet;
    cout << "Введите утеплитель: ";
    cin >> uteplitel;
    cout << "Введите плотность: ";
    cin >> plotnost;

    return new Zimnyaya(material, cena, razmer, cvet, uteplitel, plotnost);
}

int main() {
    int choice;
    Odezhda* odezhda = nullptr; // Текущая одежда
    vector<Odezhda*> odezhdaList; // Список одежды

    do {
        cout << "\nМеню:\n";
        cout << "2. Создать летнюю одежду\n";
        cout << "3. Создать зимнюю одежду\n";
        cout << "4. Показать информацию\n";
        cout << "5. Надеть\n";
        cout << "6. Снять\n";
        cout << "7. Купить\n";
        cout << "8. Постирать\n";
        cout << "9. Высушить\n";
        cout << "10. Защищает от солнца\n";
        cout << "11. Дышит\n";
        cout << "12. Согревает\n";
        cout << "13. Сохраняет тепло\n";
        cout << "14. Защищает от ветра\n";
        cout << "0. Выход\n";
        cout << "Твой выбор: ";
        cin >> choice;

        switch (choice) {
        case 2:
            odezhda = creatOdezhaL();
            if (odezhda) {
                odezhdaList.push_back(odezhda);
                cout << "Летняя одежда создана и добавлена в гардероб.\n";
            }
            break;
        case 3:
            odezhda = creatOdezhaZ();
            if (odezhda) {
                odezhdaList.push_back(odezhda);
                cout << "Зимняя одежда создана и добавлена в гардероб.\n";
            }
            break;
        case 4:
            if (!odezhdaList.empty()) {
                cout << "Содержимое гардероба:\n";
                for (size_t i = 0; i < odezhdaList.size(); ++i) {
                    cout << "Одежда " << i + 1 << ":\n";
                    odezhdaList[i]->displayInfo();
                    cout << "-----------------------\n";
                }
            }
            else {
                cout << "Гардероб пуст. Сначала создайте одежду.\n";
            }
            break;
        case 5:
            if (odezhda) odezhda->nadet();
            else cout << "Сначала создайте одежду.\n";
            break;
        case 6:
            if (odezhda) odezhda->snat();
            else cout << "Сначала создайте одежду.\n";
            break;
        case 7:
            if (odezhda) odezhda->kupit();
            else cout << "Сначала создайте одежду.\n";
            break;
        case 8:
            if (odezhda) odezhda->postirat();
            else cout << "Сначала создайте одежду.\n";
            break;
        case 9:
            if (odezhda) odezhda->sushit();
            else cout << "Сначала создайте одежду.\n";
            break;
        case 10:
            if (auto* l = dynamic_cast<Letnyaya*>(odezhda)) l->zashishatOtSolnca();
            else cout << "Эта одежда не летняя.\n";
            break;
        case 11:
            if (auto* l = dynamic_cast<Letnyaya*>(odezhda)) l->dyshat();
            else cout << "Эта одежда не летняя.\n";
            break;
        case 12:
            if (auto* z = dynamic_cast<Zimnyaya*>(odezhda)) z->sogrevat();
            else cout << "Эта одежда не зимняя.\n";
            break;
        case 13:
            if (auto* z = dynamic_cast<Zimnyaya*>(odezhda)) z->sohranyatTeplo();
            else cout << "Эта одежда не зимняя.\n";
            break;
        case 14:
            if (auto* z = dynamic_cast<Zimnyaya*>(odezhda)) z->nePropuskatVeter();
            else cout << "Эта одежда не зимняя.\n";
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    // Освобождение памяти
    for (auto* item : odezhdaList) {
        delete item;
    }

    return 0;
}
