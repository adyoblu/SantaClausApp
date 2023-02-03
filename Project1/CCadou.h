#pragma once
#include <string>
#include <vector>

class CCadou
{
private:
    int id;
    std::string denumire;
    std::string culoare;
    bool hartieCutie;
    int nrComponente;
    std::vector<int> componente;
public:
    // Constructor
    CCadou() : id(0), denumire(""), culoare(""), hartieCutie(""), nrComponente(0), componente({}) {}
    explicit CCadou(int id, std::string denumire, std::string culoare, bool hartieCutie, int nrComponente, std::vector<int> componente)
        : id(id), denumire(denumire), culoare(culoare), hartieCutie(hartieCutie), nrComponente(nrComponente), componente(componente) {}
    // Move constructor
    CCadou(CCadou&& other) noexcept
        : id(other.id), denumire(std::move(other.denumire)), culoare(std::move(other.culoare)), hartieCutie(other.hartieCutie), nrComponente(other.nrComponente), componente(std::move(other.componente)) {
        other.id = 0;
        other.denumire = "";
        other.culoare = "";
        other.hartieCutie = 0;
        other.nrComponente = 0;
        other.componente = {};
    }

    // Destructor
    virtual ~CCadou() = default;
    // Getteri
    int getId() const { return id; }
    std::string getDenumire() const { return denumire; }
    std::string getCuloare() const { return culoare; }
    std::string getHartieCutie() const { return hartieCutie == 0 ? "cutie" : "hartie"; }
    int getNrComponente() const { return nrComponente; }
    std::vector<int> getComponente() const { return componente; }

    // Setteri
    void setId(int newId) { id = newId; }
    void setDenumire(std::string newDenumire) { denumire = newDenumire; }
    void setCuloare(std::string newCuloare) { culoare = newCuloare; }
    void setHartieCutie(bool hartieCutie) { this->hartieCutie = hartieCutie; }
    void setNrComponente(int nrComponente) { this->nrComponente = nrComponente; }
    void setComponente(std::vector<int> newComponente) { componente = newComponente; }
};

