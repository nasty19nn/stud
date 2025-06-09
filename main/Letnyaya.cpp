#include "Letnyaya.h"
#include <iostream>

Letnyaya::Letnyaya(std::string material, double cena, std::string razmer, std::string cvet,
    std::string ventilatsiya, std::string otkrytost)
    : Odezhda(material, cena, razmer, cvet), ventilatsiya(ventilatsiya), otkrytost(otkrytost) {
}

std::string Letnyaya::getVentilyatsiya() const { return ventilatsiya; }
std::string Letnyaya::getOtkrytost() const { return otkrytost; }

void Letnyaya::setVentilyatsiya(const std::string& newVentilyatsiya) { ventilatsiya = newVentilyatsiya; }
void Letnyaya::setOtkrytost(const std::string& newOtkrytost) { otkrytost = newOtkrytost; }

void Letnyaya::postirat() { std::cout << "Быстрая стирка\n"; }
void Letnyaya::sushit() { std::cout << "Быстрая сушка\n"; }

void Letnyaya::zashishatOtSolnca() { std::cout << "Защищает от солнца\n"; }
void Letnyaya::dyshat() { std::cout << "Дышит\n"; }

void Letnyaya::displayInfo() const {
    std::cout << "Материал: " << material << "\n"
        << "Цена: " << cena << "\n"
        << "Размер: " << razmer << "\n"
        << "Цвет: " << cvet << "\n"
        << "Вентиляция: " << ventilatsiya << "\n"
        << "Открытость: " << otkrytost << "\n";
}
