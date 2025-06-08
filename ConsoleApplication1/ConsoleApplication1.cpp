
#include <iostream>
#include <string>
#include <cstdlib>//для красоты консольки
#include <thread>
#include<chrono>
#include <vector>
#include <memory> // Для умных указателей

using namespace std;

void clearConsole() {
    std::system("cls"); // Windows

}

void delayAndClear(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    clearConsole();
}

// Класс Одежда (родительский абстрактный)
class Odezhda {
protected:
    string material;
    double cena;
    string razmer;
    string cvet;

public:
    // Конструктор
    Odezhda(string material, double cena, string razmer, string cvet) :
        material(material), cena(cena), razmer(razmer), cvet(cvet) {
    }

    // Геттеры (для доступа к защищенным переменным)
    string getMaterial() const { return material; }
    double getCena() const { return cena; }
    string getRazmer() const { return razmer; }
    string getCvet() const { return cvet; }

    // Сеттеры (для изменения защищенных переменных, при необходимости)
    void setMaterial(const string& newMaterial) { material = newMaterial; }
    void setCena(double newCena) { cena = newCena; }
    void setRazmer(const string& newRazmer) { razmer = newRazmer; }
    void setCvet(const string& newCvet) { cvet = newCvet; }

    // Методы
    void nadet() { cout << "Одежда надета\n"; }
    void snat() { cout << "Одежда снята\n"; }
    void kupit() { cout << "Одежда куплена\n"; }
    virtual void postirat() { cout << "Одежда постирана\n"; } // virtual - для переопределения
    virtual void sushit() { cout << "Одежда высушена\n"; } // virtual - для переопределения

    virtual void displayInfo() const = 0; // Чисто виртуальная функция (делает класс абстрактным)

};

// Класс Летняя (наследник)
class Letnyaya : public Odezhda {
private:
    string ventilatsiya;
    string otkrytost;

public:
    // Конструктор
    Letnyaya(string material, double cena, string razmer, string cvet, string ventilatsiya, string otkrytost) :
        Odezhda(material, cena, razmer, cvet), ventilatsiya(ventilatsiya), otkrytost(otkrytost) {
    }

    // Геттеры для свойств летней одежды
    string getVentilyatsiya() const { return ventilatsiya; }
    string getOtkrytost() const { return otkrytost; }

    //Сеттеры для свойств летней одежды
    void setVentilyatsiya(const string& newVentilyatsiya) { ventilatsiya = newVentilyatsiya; }
    void setOtkrytost(const string& newOtkrytost) { otkrytost = newOtkrytost; }

    // Переопределенные методы
    void postirat() override { cout << "Быстрая стирка\n"; }
    void sushit() override { cout << "Быстрая сушка\n"; }

    // Методы летней одежды
    void zashishatOtSolnca() { cout << "Защищает от солнца\n"; }
    void dyshat() { cout << "Дышит\n"; }

    void displayInfo() const override {
        cout << "Материал: " << material << endl;
        cout << "Цена: " << cena << endl;
        cout << "Размер: " << razmer << endl;
        cout << "Цвет: " << cvet << endl;
        cout << "Вентиляция: " << ventilatsiya << endl;
        cout << "Открытость: " << otkrytost << endl;
    }
};

// Класс Зимняя (наследник)
class Zimnyaya : public Odezhda {
private:
    string uteplitel;
    double plotnost;

public:
    // Конструктор
    Zimnyaya(string material, double cena, string razmer, string cvet, string uteplitel, double plotnost) :
        Odezhda(material, cena, razmer, cvet), uteplitel(uteplitel), plotnost(plotnost) {
    }

    // Геттеры для свойств зимней одежды
    string getUteplitel() const { return uteplitel; }
    double getPlotnost() const { return plotnost; }

    //Сеттеры для свойств зимней одежды
    void setUteplitel(const string& newUteplitel) { uteplitel = newUteplitel; }
    void setPlotnost(double newPlotnost) { plotnost = newPlotnost; }

    // Переопределенные методы
    void postirat() override { cout << "Деликатная стирка\n"; }
    void sushit() override { cout << "Долгая сушка\n"; }

    // Методы зимней одежды
    void sogrevat() { cout << "Согревает\n"; }
    void sohranyatTeplo() { cout << "Сохраняет тепло\n"; }
    void nePropuskatVeter() { cout << "Защищает от ветра\n"; }

    void displayInfo() const override {
        cout << "Материал: " << material << endl;
        cout << "Цена: " << cena << endl;
        cout << "Размер: " << razmer << endl;
        cout << "Цвет: " << cvet << endl;
        cout << "Утеплитель: " << uteplitel << endl;
        cout << "Плотность: " << plotnost << endl;
    }
};

Letnyaya* creatOdezhaL()
{
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

Zimnyaya* creatOdezhaZ()
{
    string material;
    double cena;
    string razmer;
    string cvet;
    string uteplitel;
    double plotnost;
    bool naches;

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
    Odezhda* odezhda = nullptr;  // Указатель на объект одежды (инициализирован nullptr)
    std::vector<Odezhda*> odezhdaList; // Вектор для хранения созданной одежды

    do {
        // Вывод меню
        cout << "Меню:\n";
        cout << "2. Создать летнюю одежду\n";
        cout << "3. Создать зимнюю одежду\n";
        cout << "4. Показать информацию \n";
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
                odezhdaList.push_back(odezhda); // Добавляем объект в вектор
                std::cout << "Летняя одежда создана и добавлена в массив.\n";
            }
            else {
                std::cout << "Не удалось создать летнюю одежду.\n";
            }
            break;
        case 3:
            odezhda = creatOdezhaZ();
            if (odezhda) {
                odezhdaList.push_back(odezhda); // Добавляем объект в вектор
                std::cout << "Зимняя одежда создана и добавлена в массив.\n";
            }
            else {
                std::cout << "Не удалось создать зимнюю одежду.\n";
            }
            break;
        case 4:
            if (!odezhdaList.empty()) {
                cout << "Содержимое гардероба:\n";
                for (size_t i = 0; i < odezhdaList.size(); ++i) {
                    cout << "Одежда " << i + 1 << ":\n";
                    odezhdaList[i]->displayInfo();
                    cout << "-----------------------\n"; // Разделитель для удобства чтения
                }
            }
            else {
                cout << "Сначала создайте одежду.\n";
            }
            break;
        case 5:
            if (odezhda != nullptr) {
                odezhda->nadet();
            }
            else {
                cout << "Сначала создайте одежду.\n";
            }
            break;
        case 6:
            if (odezhda != nullptr) {
                odezhda->snat();
            }
            else {
                cout << "Сначала создайте одежду.\n";
            }
            break;
        case 7:
            if (odezhda != nullptr) {
                odezhda->kupit();
            }
            else {
                cout << "Сначала создайте одежду.\n";
            }
            break;
        case 8:
            if (odezhda != nullptr) {
                odezhda->postirat();
            }
            else {
                cout << "Сначала создайте одежду.\n";
            }
            break;
        case 9:
            if (odezhda != nullptr) {
                odezhda->sushit();
            }
            else {
                cout << "Сначала создайте одежду.\n";
            }
            break;
        case 10:
            if (dynamic_cast<Letnyaya*>(odezhda)) {
                dynamic_cast<Letnyaya*>(odezhda)->zashishatOtSolnca();
            }
            else {
                std::cout << "Эта одежда не летняя.\n";
            }
            break;
        case 11:
            if (dynamic_cast<Letnyaya*>(odezhda)) {
                dynamic_cast<Letnyaya*>(odezhda)->dyshat();
            }
            else {
                std::cout << "Эта одежда не летняя.\n";
            }
            break;
        case 12:
            if (dynamic_cast<Zimnyaya*>(odezhda)) {
                dynamic_cast<Zimnyaya*>(odezhda)->sogrevat();
            }
            else {
                std::cout << "Эта одежда не зимняя.\n";
            }
            break;
        case 13:
            if (dynamic_cast<Zimnyaya*>(odezhda)) {
                dynamic_cast<Zimnyaya*>(odezhda)->sohranyatTeplo();
            }
            else {
                std::cout << "Эта одежда не зимняя.\n";
            }
            break;
        case 14:
            if (dynamic_cast<Zimnyaya*>(odezhda)) {
                dynamic_cast<Zimnyaya*>(odezhda)->nePropuskatVeter();
            }
            else {
                std::cout << "Эта одежда не зимняя.\n";
            }
            break;
        case 0:
            std::cout << "Выход.\n";
            break;
        default:
            std::cout << "Некорректный выбор.\n";
        }
        //delayAndClear(3); // Задержка в 3 секунды, затем очистка
        
    } while (choice != 0);

    //Освобождаем память в конце программы
    if (odezhda != nullptr) {
        delete odezhda;
    }

    return 0;
}