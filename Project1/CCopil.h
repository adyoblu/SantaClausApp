#pragma once
#include <vector>
#include <string>
#include "CCadou.h"
using namespace std;

class CCopil {
private:
    std::string nume;
    std::string prenume;
    std::string dataNastere;
    bool cuminteRau;
    std::vector<int> indexAdresa;
    int nrCadouriDorite;
    std::vector<int> indexCadouriDorite;
    int nrCadouriPrimite;
    std::vector<int> indexCadouriPrimite;
    int adresaCurenta;
public:
    //constructor
    CCopil(std::string nume, std::string prenume, std::string dataNastere, bool cuminteRau, std::vector<int> indexAdresa, int nrCadouriDorite, std::vector<int> indexCadouriDorite, int nrCadouriPrimite, std::vector<int> indexCadouriPrimite, int adresaCurenta) :
        nume(nume), prenume(prenume), dataNastere(dataNastere), cuminteRau(cuminteRau), indexAdresa(indexAdresa), nrCadouriDorite(nrCadouriDorite), indexCadouriDorite(indexCadouriDorite), nrCadouriPrimite(nrCadouriPrimite), indexCadouriPrimite(indexCadouriPrimite), adresaCurenta(adresaCurenta) {}
    explicit CCopil(CCopil&& other) noexcept
    :  nume(std::move(other.nume)),
        prenume(std::move(other.prenume)),
        dataNastere(std::move(other.dataNastere)),
        cuminteRau(other.cuminteRau),
        indexAdresa(std::move(other.indexAdresa)),
        nrCadouriDorite(other.nrCadouriDorite),
        indexCadouriDorite(std::move(other.indexCadouriDorite)),
        nrCadouriPrimite(other.nrCadouriPrimite),
        indexCadouriPrimite(std::move(other.indexCadouriPrimite)),
        adresaCurenta(other.adresaCurenta)
    {
        other.nrCadouriDorite = 0;
        other.nrCadouriPrimite = 0;
        other.adresaCurenta = 0;
    }
    //destructor
    virtual ~CCopil() { nume.clear(); prenume.clear(); dataNastere.clear(); cuminteRau = 0; indexAdresa.clear(); nrCadouriDorite = 0; indexCadouriDorite.clear(); nrCadouriPrimite = 0; indexCadouriPrimite.clear(); adresaCurenta = 0; }
    //getters
    std::string getNume() { return nume; }
    std::string getPrenume() { return prenume; }
    std::string getDataNastere() { return dataNastere; }
    bool getCuminteRau() { return cuminteRau; }
    std::vector<int> getIndexAdresa() { return indexAdresa; }
    int getNrCadouriDorite() { return nrCadouriDorite; }
    std::vector<int> getIndexCadouriDorite() { return indexCadouriDorite; }
    int getNrCadouriPrimite() { return nrCadouriPrimite; }
    std::vector<int> getIndexCadouriPrimite() { return indexCadouriPrimite; }
    int getAdresaCurenta() { return adresaCurenta; }

    //setters
    void setNume(std::string nume) { this->nume = nume; }
    void setPrenume(std::string prenume) { this->prenume = prenume; }
    void setDataNastere(std::string dataNastere) { this->dataNastere = dataNastere; }
    void setCuminteRau(bool cuminteRau) { this->cuminteRau = cuminteRau; }
    void setIndexAdresa(std::vector<int> indexAdresa) { this->indexAdresa = indexAdresa; }
    void setNrCadouriDorite(int nrCadouriDorite) { this->nrCadouriDorite = nrCadouriDorite; }
    void setIndexCadouriDorite(std::vector<int> indexCadouriDorite) { this->indexCadouriDorite = indexCadouriDorite; }
    void setNrCadouriPrimite(int nrCadouriPrimite) { this->nrCadouriPrimite = nrCadouriPrimite; }
    void setIndexCadouriPrimite(std::vector<int> indexCadouriPrimite) { this->indexCadouriPrimite = indexCadouriPrimite; }
    void setAdresaCurenta(int adresaCurenta) { this->adresaCurenta = adresaCurenta; }
};