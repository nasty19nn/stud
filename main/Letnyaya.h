#pragma once
#include "Odezhda.h"

class Letnyaya : public Odezhda {
private:
    std::string ventilatsiya;
    std::string otkrytost;

public:
    Letnyaya(std::string material, double cena, std::string razmer, std::string cvet,
        std::string ventilatsiya, std::string otkrytost);

    std::string getVentilyatsiya() const;
    std::string getOtkrytost() const;

    void setVentilyatsiya(const std::string& newVentilyatsiya);
    void setOtkrytost(const std::string& newOtkrytost);

    void postirat() override;
    void sushit() override;

    void zashishatOtSolnca();
    void dyshat();

    void displayInfo() const override;
};
