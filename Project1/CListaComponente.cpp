#define _CRT_SECURE_NO_WARNINGS
#include "CListaComponente.h"
#include "MyNamespace.h"
#include <fstream>
#include <sstream>
#include <iostream>

CListaComponente::CListaComponente()
{
	loadFile();
}

void CListaComponente::print()
{
    for (auto component : listaComponente) {
        std::cout << "Id: " << component->getId() << std::endl;
        std::cout << "Nume componenta: " << component->getNumeComponenta() << std::endl;
        std::cout << "Latime: " << component->getLatime() << std::endl;
        std::cout << "Lungime: " << component->getLungime() << std::endl;
        std::cout << "Atribute speciale: " << std::endl;

        auto atributes = component->getAtribute();
        for (auto it = atributes.begin(); it != atributes.end(); it++)
            std::cout << it->first << " : " << it->second << std::endl;
        cout << endl;
    }
}

void CListaComponente::loadFile()
{
    std::ifstream file("lista_componente.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int id, atributeSpeciale;
            std::string numeComponenta, atribute_key, atribute_value, latimeLungimeString;
            int latime, lungime;
            ss >> id >> numeComponenta >> latimeLungimeString >> atributeSpeciale;
            sscanf(latimeLungimeString.c_str(), "%dx%d", &latime, &lungime);
            CComponenta* c = new CComponenta();
            c->setId(id);
            c->setNumeComponenta(numeComponenta);
            c->setLatime(latime);
            c->setLungime(lungime);
            c->setAtributeSpeciale(atributeSpeciale);
            for (int i = 0; i < atributeSpeciale; i++) {
                ss >> atribute_key >> atribute_value;
                c->addAtribute(atribute_key, atribute_value);
            }
            listaComponente.push_back(c);
            nrComponente++;
        }
        file.close();
    }
}

void CListaComponente::Add()
{
    CComponenta* newComponent = new CComponenta();
    std::string key, value;
    int id = listaComponente.empty() ? 1 : listaComponente.back()->getId() + 1;
    newComponent->setId(id);
    MyNamespace::smart("Adauga Componenta");
    std::cout << "Nume componenta: ";
    std::string numeComponenta;
    std::cin >> numeComponenta;
    newComponent->setNumeComponenta(numeComponenta);

    do {
        std::cout << "Latime: ";
        int latime;
        std::cin >> latime;
        if (std::cin.fail()) {
            std::cout << "Invalid input, please enter a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            newComponent->setLatime(latime);
        }
    } while (std::cin.fail());

    do {
        std::cout << "Lungime: ";
        int lungime;
        std::cin >> lungime;
        if (std::cin.fail()) {
            std::cout << "Invalid input, please enter a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            newComponent->setLungime(lungime);
        }
    } while (std::cin.fail());
    std::cout << "Atribute speciale (introduceti pereche cheie:valoare si apoi apasati space): " << std::endl;
    int nr = 0;
    do {
        std::string key;
        std::string value;
        std::vector<std::pair<std::string, std::string>> v = newComponent->getAtribute();
        std::cout << "Introduceti atribut: ";
        std::cin >> key;
        std::cout << "Introduceti caracteristica: ";
        std::cin >> value;
        v.push_back(std::make_pair(key, value));
        nr++;
        newComponent->setAtribute(v);
        newComponent->setAtributeSpeciale(nr);
        std::cout << "Doriti sa adaugati alte atribute?" << "\nAlege optiunea dorita: \n1. Da\n2. Nu\n";
        int a;
        std::cin >> a;
        while (a != 1 && a != 2) {
            std::cout << "Ati introdus gresit! Introduceti o optiune din cele din meniu.\n";
            std::cin >> a;
        }
        if (a == 2) break;
    } while (1);

    std::cout << "\n\nComponenta creeata cu succes!";
    listaComponente.push_back(newComponent);
    nrComponente++;
    writeFile();
}

void CListaComponente::Delete()
{
    MyNamespace::smart("Delete Componenta");
    if (!listaComponente.empty()) {
        print();
        cout << "Introdu id componenta pentru a sterge din lista: ";
        int option;
        cin >> option;
        while (option > getNr()) {
            cout << "Introduceti un numar valid" << endl;
            cin >> option;
        }
        listaComponente.erase(listaComponente.begin() + option - 1);
        nrComponente--;
        writeFile();
        cout << "\n\nComponenta a fost stearsa cu succes in fisier!" << endl;
    }
    else {
        cout << "Nu este nici1 cadou in lista de cadouri. Vei fi redirectionat catre meniul principal!";
        return;
    }
    listaComponente.clear();
    nrComponente = 0;
    loadFile();
}

void CListaComponente::Update()
{
    MyNamespace::smart("Update Componenta");
    print();
    cout << "Ce componenta vrei sa modifici? (1-" << getNr() << ")" << endl;
    int x;
    while (!(std::cin >> x) || x < 1 || x > getNr()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }
    system("cls");
    if (!listaComponente.empty()) {
        for (int i = 0; i < nrComponente; i++) {
            if (listaComponente[i]->getId() == x) {//cadoul introdus de utilizator
                int option[4] = { 1, 2, 3, 4 };
                cout << option[0] << ". Nume: " << listaComponente[i]->getNumeComponenta() << endl;
                cout << option[1] << ". Lungime: " << listaComponente[i]->getLungime() << endl;
                cout << option[2] << ". Latime: " << listaComponente[i]->getLatime() << endl;
                cout << option[3] << ". Atribute speciale: \n";
                std::vector<std::pair<std::string, std::string>> v = listaComponente[i]->getAtribute();
                for (auto i : v)
                    cout << i.first << " -> " << i.second <<endl;
                cout << endl;
                cout << endl << endl << "Ce camp doresti sa modifici ?" << endl << "(introdu numarul): ";
                int k;
                cin >> k;
                for (auto& j : option) {
                    if (j == k) {
                        cout << "NEW\n";
                        if (k == 1) {//schimba denumire
                            cout << "Introdu noua denumire: ";
                            string a;
                            cin >> a;
                            listaComponente[i]->setNumeComponenta(a);
                        }
                        else if (k == 2) {//schimba lungime
                            cout << "Introdu noua lungime: ";
                            int a;
                            cin >> a;
                            listaComponente[i]->setLungime(a);
                        }
                        else if (k == 3) {//schimba latime
                            std::cout << "Introdu noua latime: ";
                            int a;
                            cin >> a;
                            listaComponente[i]->setLatime(a);
                        }
                        else if (k == 4) {//schimba atribute
                            cout << "\n\nMomentan este in lucru! Revenim mai tarziu.\nVei fi redirectionat catre meniul principal" << endl;
                        }
                        if(k != 4)
                            cout << "Campurile au fost schimbate cu succes!";
                        writeFile();
                        break;
                    }
                }
            }
        }
    }
    else {
        cout << "Nu este nici1 cadou in lista de cadouri. Vei fi redirectionat catre meniul principal!";
        return;
    }
}

void CListaComponente::writeFile()
{
    std::ofstream outFile("lista_componente.txt");
    for (auto component : listaComponente) {
        outFile << component->getId() << " ";
        outFile << component->getNumeComponenta() << " ";
        outFile << component->getLatime() << "x" << component->getLungime() << " ";
        outFile << component->getAtributeSpeciale() << " ";
        auto atributes = component->getAtribute();
        for (auto it = atributes.begin(); it != atributes.end(); it++)
            outFile << it->first << " " << it->second << " ";
        outFile << std::endl;
    }
    outFile.close();
}

std::ostream& operator<<(std::ostream& out, CListaComponente*& y) {
    system("cls");
    for (auto component : y->listaComponente) {
        out << "Id: " << component->getId() << std::endl;
        out << "Nume componenta: " << component->getNumeComponenta() << std::endl;
        out << "Latime: " << component->getLatime() << std::endl;
        out << "Lungime: " << component->getLungime() << std::endl;
        out << "Atribute speciale: " << std::endl;

        auto atributes = component->getAtribute();
        for (auto it = atributes.begin(); it != atributes.end(); it++)
            out << it->first << " : " << it->second << std::endl;

        cout << endl;
    }
    return out;
}
