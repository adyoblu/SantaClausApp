#include "CListaCadou.h"
#include "MyNamespace.h"
#include "CListaComponente.h"
#include <fstream>
#include <iostream>
#include <sstream>

CListaCadou::CListaCadou()
{
	loadFile();
}

void CListaCadou::print()
{
    system("cls");
    for (int i = 0; i < nrCadouri; i++) {
        std::cout << "Id: " << listaCadouri[i]->getId() << std::endl;
        std::cout << "Denumire: " << listaCadouri[i]->getDenumire() << std::endl;
        std::cout << "Culoare: " << listaCadouri[i]->getCuloare() << std::endl;
        std::cout << "Hartie/Cutie: " << listaCadouri[i]->getHartieCutie() << std::endl;
        std::cout << "Componente: ";
        for (const auto& comp : listaCadouri[i]->getComponente())
            std::cout << comp << " ";
        std::cout << std::endl << std::endl;
    }
    
}

void CListaCadou::loadFile()
{
    std::ifstream file("lista_cadouri.txt");
    if (!file.good())
    {
        std::ofstream newFile("lista_cadouri.txt");
        newFile.close();
    }
    else
    {
        std::string line;
        while (getline(file, line))
        {
            std::vector<std::string> fields;
            std::stringstream ss(line);
            std::string item;
            while (ss >> item)
            {
                fields.push_back(item);
            }
            CCadou* cadou = new CCadou();
            cadou->setId(std::stoi(fields[0]));
            cadou->setDenumire(fields[1]);
            cadou->setCuloare(fields[2]);
            cadou->setHartieCutie(stoi(fields[3]));
            int nrComponente = std::stoi(fields[4]);
            std::vector<int> componente;
            for (int i = 0; i < nrComponente; i++)
            {
                componente.push_back(std::stoi(fields[5 + i]));
            }
            cadou->setComponente(componente);
            listaCadouri.push_back(std::move(cadou));
        }
        nrCadouri = listaCadouri.size();
        file.close();
    }
}

void CListaCadou::Add()
{
    MyNamespace::smart("Adauga cadou");
    int id, nrComponente;
    std::string denumire, culoare;
    bool hartieCutie;
    std::vector<int> componente;
    std::cout << "Introdu numele unei jucarii noi: ";
    std::cin >> denumire;
    auto iter = std::find_if(listaCadouri.begin(), listaCadouri.end(),
        [denumire](const CCadou* cadou) { return cadou->getDenumire() == denumire; });

    if (iter != listaCadouri.end())
    {
        std::cout << "Jucaria " << denumire << " exista deja in lista." << std::endl;
    }
    else
    {
        CListaComponente a;
        id = nrCadouri + 1;
        std::cout << "Introdu culoarea: ";
        std::cin >> culoare;
        std::cout << "Cadoul sa fie infasurat in hartie sau in cutie?(1 pentru hartie, 0 pentru cutie)? ";
        std::cin >> hartieCutie;
        while (hartieCutie != 1 && hartieCutie != 0) {
            std::cout << "Introducere incorecta. Introduceti 1 pentru hartie sau 0 pentru cutie: ";
            std::cin >> hartieCutie;
        }

        bool success = false;
        while (!success)
        {
            std::cout << "Cate componente are jucaria cea noua?(1-"<<a.getNr()<<"): ";
            if (std::cin >> nrComponente)
            {
                if (nrComponente < 1 || nrComponente > a.getNr())
                {
                    std::cout << "\nEROARE!!! Numarul introdus nu este valid. Introdu un numar intre 1 si " << a.getNr() << ".";
                }
                else
                {
                    success = true;
                }
            }
            else
            {
                std::cout << "\nEROARE!!! Valoarea introdusa nu este un numar intreg. Introdu un numar intre 1 si " << a.getNr() << " : "<<endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }


        system("cls");
        for (int i = 0; i < nrComponente; i++) {
            int comp;
            for (auto& x : a.getListaComponente()) {
                std::cout << x->getId() << ". " << x->getNumeComponenta() << " " << x->getLatime() << "x" << x->getLungime() << std::endl;
                for (auto& s : x->getAtribute())
                    std::cout << "(" << s.first << " -> " << s.second << ")" << std::endl;
            }
            std::cout << "Introdu componenta " << i + 1 << " : ";

            bool success = false;
            while (!success)
            {
                std::string line;
                cin >> line;
                try
                {
                    comp = std::stoi(line);
                    for (auto& x : a.getListaComponente())
                        if (comp == x->getId()) success = true;
                    if(success == false)
                    {
                        std::cout << "Componenta introdusa nu exista in lista. Introdu o alta componenta: ";
                    }
                }
                catch (const std::exception&)
                {
                    std::cout << "Valoarea introdusa nu este un numar intreg. Introdu o alta componenta: ";
                }
            }
        componente.push_back(comp);
        }
        nrCadouri++;
        CCadou* cadou = new CCadou(id, denumire, culoare, hartieCutie, nrComponente, componente);
        listaCadouri.push_back(cadou);
        std::cout<<"Cadoul a fost adaugat cu succes in fisier!" << std::endl;
        writeFile();
    }
}

void CListaCadou::Delete()
{
    MyNamespace::smart("Sterge cadou");
    if (!listaCadouri.empty()) {
        print();
        cout << "Introdu index cadou pentru a sterge din lista: ";
        int option;
        cin >> option;
        while (option > getNr()) {
            cout << "Introduceti un numar valid" << endl;
            cin >> option;
        }
        listaCadouri.erase(listaCadouri.begin() + option - 1);
        nrCadouri--;
        writeFile();
        cout << "Cadoul a fost sters cu succes in fisier!" << endl;
    }
    else {
        cout << "Nu este nici1 cadou in lista de cadouri. Vei fi redirectionat catre meniul principal!";
        return;
    }
    listaCadouri.clear();
    nrCadouri = 0;
    loadFile();
}

void CListaCadou::Update()
{
    MyNamespace::smart("Update cadou");
    print();
    cout << "Ce cadou vrei sa modifici? (1-" << getNr() << ")" << endl;
    int x;
    while (!(std::cin >> x) || x < 1 || x > getNr()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }
    system("cls");
    if (!listaCadouri.empty()) {
        for (int i = 0; i < nrCadouri; i++) {
            if (listaCadouri[i]->getId() == x) {//cadoul introdus de utilizator
                int option[4] = { 1, 2, 3, 4 };
                cout << option[0] << ". Denumire: " << listaCadouri[i]->getDenumire() << endl;
                cout << option[1] << ". Culoare: " << listaCadouri[i]->getCuloare() << endl;
                cout << option[2] << ". Hartie/Cutie: " << listaCadouri[i]->getHartieCutie() << endl;
                cout << option[3] << ". Componente: ";
                CListaComponente y;
                for (auto index : listaCadouri[i]->getComponente())
                    for (auto i : y.getListaComponente())
                        if (index == i->getId())
                            cout << i->getNumeComponenta() << " ";
                cout << endl << endl << "Ce camp doresti sa modifici ?" << endl << "(introdu numarul): ";
                int k;
                cin >> k;
                for (auto& j : option) {
                    if (j == k) {//schimba denumire
                        cout << "NEW\n";
                        if (k == 1) {
                            cout << "Introdu noua denumire: ";
                            string a;
                            cin >> a;
                            listaCadouri[i]->setDenumire(a);
                        }
                        else if (k == 2) {//schimba culoare
                            cout << "Introdu noua culoare: ";
                            string a;
                            cin >> a;
                            listaCadouri[i]->setCuloare(a);
                        }
                        else if (k == 3) {//schimba hartie/cutie
                            std::cout << "Cadoul sa fie infasurat in hartie sau in cutie?(1 pentru hartie, 0 pentru cutie)? ";
                            int a;
                            cin >> a;
                            while (a != 1 && a != 0) {
                                std::cout << "Introducere incorecta. Introduceti 1 pentru hartie sau 0 pentru cutie: ";
                                std::cin >> a;
                            }
                            listaCadouri[i]->setHartieCutie(a);
                        }
                        else if (k == 4) {//schimba componentele
                            vector<int> comp;
                            int nrComp;
                            cout << "Cate componente vrei sa aiba acest cadou?(maximul componente din fisier " << y.getNr() << ") :" << endl;
                            while (!(std::cin >> nrComp) || nrComp < 1 || nrComp > y.getNr()) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Introducere incorecta. Introduceti un nr. intre 1 si " << y.getNr() << endl;
                                continue;
                            }
                            for (int j = 0; j < nrComp; ++j) {
                                int k = 1;
                                for (auto i : y.getListaComponente()) {
                                    cout << k << ". " << i->getNumeComponenta() << endl;
                                    k++;
                                }
                                cout << "\nAlege componenta nr. " << j + 1 << "\n";
                                int c;
                                do {
                                    std::cin >> c;
                                    if (std::cin.fail() || c < 1 || c > y.getNr()) {
                                        std::cout << "Invalid input. Please try again." << std::endl;
                                        std::cin.clear();
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                } while (std::cin.fail() || c < 1 || c > y.getNr());
                                

                                comp.push_back(c);
                            }
                            listaCadouri[i]->setComponente(comp);
                            listaCadouri[i]->setNrComponente(nrComp);
                        }
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

void CListaCadou::writeFile()
{
    std::ofstream file("lista_cadouri.txt");
    for (auto& cadou : listaCadouri)
    {
        file << cadou->getId() << " " << cadou->getDenumire() << " " << cadou->getCuloare() << " ";
        if (cadou->getHartieCutie() == "hartie") file << "1";
        else file << "0";
        file<< " " << cadou->getComponente().size() << " ";
        for (auto componenta : cadou->getComponente())
            file << componenta << " ";
        file << std::endl;
    }
    file.close();
}