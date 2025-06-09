#pragma once
#include <string>
#include <iostream>

class Odezhda {
protected:
    std::string material;
    double cena;
    std::string razmer;
    std::string cvet;

public:
    Odezhda(std::string material, double cena, std::string razmer, std::string cvet);
    virtual ~Odezhda() = default;

    std::string getMaterial() const;
    double getCena() const;
    std::string getRazmer() const;
    std::string getCvet() const;

    void setMaterial(const std::string& newMaterial);
    void setCena(double newCena);
    void setRazmer(const std::string& newRazmer);
    void setCvet(const std::string& newCvet);

    void nadet();
    void snat();
    void kupit();
    virtual void postirat();
    virtual void sushit();

    virtual void displayInfo() const = 0;
};
