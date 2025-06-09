#pragma once
#include "Odezhda.h"

class Zimnyaya : public Odezhda {
private:
    std::string uteplitel;
    double plotnost;

public:
    Zimnyaya(std::string material, double cena, std::string razmer, std::string cvet,
        std::string uteplitel, double plotnost);

    std::string getUteplitel() const;
    double getPlotnost() const;

    void setUteplitel(const std::string& newUteplitel);
    void setPlotnost(double newPlotnost);

    void postirat() override;
    void sushit() override;

    void sogrevat();
    void sohranyatTeplo();
    void nePropuskatVeter();

    void displayInfo() const override;
};
