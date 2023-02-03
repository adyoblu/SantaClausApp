#include "CListaAdresa.h"
#include <fstream>
#include <iostream>

CListaAdresa::CListaAdresa()
{
	loadFile();
}

void CListaAdresa::print()
{
    for (int i = 0; i < nrAdrese; i++) {
        std::cout << "Adresa: " << i + 1 << std::endl;
        std::cout << "Localitate: " << listaAdrese[i]->getLocalitate() << std::endl;
        std::cout << "Strada: " << listaAdrese[i]->getStrada() << std::endl;
        std::cout << "Numar: " << listaAdrese[i]->getNr() << std::endl;
    }
}

void CListaAdresa::loadFile()
{
    std::ifstream file("lista_adrese.txt");
    if (!file) {
        std::ofstream newFile("lista_adrese.txt");
        newFile.close();
    }
    else {
        int id;
        std::string localitate, strada;
        int nr;
        while (file >> id) {
            std::getline(file, localitate);
            std::getline(file, strada);
            file >> nr;
            CAdresa* adresa = new CAdresa(id, localitate, strada, nr);
            listaAdrese.push_back(std::move(adresa));
            nrAdrese++;
        }
    }
    file.close();
}
