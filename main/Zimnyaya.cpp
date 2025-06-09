#include "Zimnyaya.h"
#include <iostream>

Zimnyaya::Zimnyaya(std::string material, double cena, std::string razmer, std::string cvet,
    std::string uteplitel, double plotnost)
    : Odezhda(material, cena, razmer, cvet), uteplitel(uteplitel), plotnost(plotnost) {
}

std::string Zimnyaya::getUteplitel() const { return uteplitel; }
double Zimnyaya::getPlotnost() const { return plotnost; }

void Zimnyaya::setUteplitel(const std::string& newUteplitel) { uteplitel = newUteplitel; }
void Zimnyaya::setPlotnost(double newPlotnost) { plotnost = newPlotnost; }

void Zimnyaya::postirat() { std::cout << "Деликатная стирка\n"; }
void Zimnyaya::sushit() { std::cout << "Долгая сушка\n"; }

void Zimnyaya::sogrevat() { std::cout << "Согревает\n"; }
void Zimnyaya::sohranyatTeplo() { std::cout << "Сохраняет тепло\n"; }
void Zimnyaya::nePropuskatVeter() { std::cout << "Защищает от ветра\n"; }

void Zimnyaya::displayInfo() const {
    std::cout << "Материал: " << material << "\n"
        << "Цена: " << cena << "\n"
        << "Размер: " << razmer << "\n"
        << "Цвет: " << cvet << "\n"
        << "Утеплитель: " << uteplitel << "\n"
        << "Плотность: " << plotnost << "\n";
}
