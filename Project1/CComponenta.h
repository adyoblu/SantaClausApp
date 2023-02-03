#pragma once
#include <vector>
#include <string>

class CComponenta
{
	int id;
	std::string numeComponenta;
	int latime;
	int lungime;
	int atributeSpeciale;
	std::vector<std::pair<std::string, std::string>> atribute;
public:
    // constructor
    CComponenta() : id(0), numeComponenta(""), latime(0), lungime(0), atributeSpeciale(0), atribute({}) {}
    CComponenta(int id, std::string numeComponenta, int latime, int lungime, int atributeSpeciale,
        std::vector<std::pair<std::string, std::string>> atribute)
        : id(id), numeComponenta(std::move(numeComponenta)), latime(latime), lungime(lungime),
        atributeSpeciale(atributeSpeciale), atribute(std::move(atribute)) {}

    // move constructor
    CComponenta(CComponenta&& other) noexcept
        : id(other.id), numeComponenta(std::move(other.numeComponenta)), latime(other.latime),
        lungime(other.lungime), atributeSpeciale(other.atributeSpeciale),
        atribute(std::move(other.atribute)) {}

    // destructor
    virtual ~CComponenta() = default;

    // getters
    int getId() const { return id; }
    std::string getNumeComponenta() const { return numeComponenta; }
    int getLatime() const { return latime; }
    int getLungime() const { return lungime; }
    int getAtributeSpeciale() const { return atributeSpeciale; }
    std::vector<std::pair<std::string, std::string>> getAtribute() const { return atribute; }

    // setters
    void setId(int id) { this->id = id; }
    void setNumeComponenta(std::string numeComponenta) { this->numeComponenta = std::move(numeComponenta); }
    void setLatime(int latime) { this->latime = latime; }
    void setLungime(int lungime) { this->lungime = lungime; }
    void setAtributeSpeciale(int atributeSpeciale) { this->atributeSpeciale = atributeSpeciale; }
    void setAtribute(std::vector<std::pair<std::string, std::string>> atribute) { this->atribute = std::move(atribute); }
    void addAtribute(std::string key, std::string value) {
        atribute.push_back(std::make_pair(key, value));
    }
};

