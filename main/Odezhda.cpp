#include "Odezhda.h"

Odezhda::Odezhda(std::string material, double cena, std::string razmer, std::string cvet)
    : material(material), cena(cena), razmer(razmer), cvet(cvet) {
}

std::string Odezhda::getMaterial() const { return material; }
double Odezhda::getCena() const { return cena; }
std::string Odezhda::getRazmer() const { return razmer; }
std::string Odezhda::getCvet() const { return cvet; }

void Odezhda::setMaterial(const std::string& newMaterial) { material = newMaterial; }
void Odezhda::setCena(double newCena) { cena = newCena; }
void Odezhda::setRazmer(const std::string& newRazmer) { razmer = newRazmer; }
void Odezhda::setCvet(const std::string& newCvet) { cvet = newCvet; }

void Odezhda::nadet() { std::cout << "Одежда надета\n"; }
void Odezhda::snat() { std::cout << "Одежда снята\n"; }
void Odezhda::kupit() { std::cout << "Одежда куплена\n"; }
void Odezhda::postirat() { std::cout << "Одежда постирана\n"; }
void Odezhda::sushit() { std::cout << "Одежда высушена\n"; }
