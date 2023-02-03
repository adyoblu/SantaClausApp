#include "CListaCopil.h"
#include "CListaAdresa.h"
#include "CListaCadou.h"
#include "MyNamespace.h"
#include <conio.h>
#include "Logger.h"

CListaCopil::CListaCopil() : listaCopii({}), nrCopii(0)
{     
    loadFile();
}

void CListaCopil::print() {
    MyNamespace::smart("Toti copii");
    int i = 1;
    for (auto copil : listaCopii) {
        cout << "Id: " << i << endl;
        cout << "Nume: " << copil->getNume() << endl;
        cout << "Prenume: " << copil->getPrenume() << endl;
        cout << "Data Nasterii: " << copil->getDataNastere() << endl;
        string l = copil->getCuminteRau() == 1 ? "cuminte" : "rau";
        cout << "Cuminte sau Rau: " << l << endl;
        cout << "Index Adresa: ";
        for (auto index : copil->getIndexAdresa()) {
            cout << index << " ";
        }
        cout << endl;
        cout << "Nr Cadouri Dorite: " << copil->getNrCadouriDorite() << endl;
        cout << "Index Cadouri Dorite: ";
        for (auto index : copil->getIndexCadouriDorite()) {
            cout << index << " ";
        }
        cout << endl;
        cout << "Nr Cadouri Primite: " << copil->getNrCadouriPrimite() << endl;
        cout << "Index Cadouri Primite: ";
        for (auto index : copil->getIndexCadouriPrimite()) {
            cout << index << " ";
        }
        cout << endl;
        cout << "Index Adresa Curenta: " << copil->getAdresaCurenta() << endl;
        cout << endl << endl;
        i++;
    }
}

void CListaCopil::loadFile()
{
    numeLista = "lista_copii.txt";
    nrCopii = 0;
    std::ifstream file(numeLista);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            //nume prenume data_nastere cuminte/rau indexe_adrese nr_cadouriDorite indexe_cadouriDorite nr_cadouriPrimite indexe_cadouriPrimite index_adresaActuala
            nrCopii++;
            stringstream ss(line);
            int cadouriDorite, cadouriPrimite;
            string nume, prenume, dataNastere;
            bool cuminteRau;
            std::vector<int> indexCadouriDorite, indexCadouriPrimite, indexAdresa;
            getline(ss, nume, ' ');
            getline(ss, prenume, ' ');
            getline(ss, dataNastere, ' ');
            ss >> cuminteRau;
            int index;
            string cv;
            ss >> cv;
            stringstream adress(cv);
            while (adress >> index) {
                indexAdresa.push_back(index);
            }
            ss >> cadouriDorite;
            cv.clear();
            ss >> cv;
            stringstream dorite(cv);
            while (dorite >> index) {
                indexCadouriDorite.push_back(index);
            }
            ss >> cadouriPrimite;
            cv.clear();
            ss >> cv;
            stringstream primite(cv);
            while (primite >> index) {
                indexCadouriPrimite.push_back(index);
            }
            ss >> index;
            CCopil* copil = new CCopil(nume, prenume, dataNastere, cuminteRau, indexAdresa, cadouriDorite, indexCadouriDorite, cadouriPrimite, indexCadouriPrimite, index);
            listaCopii.push_back(std::move(copil));
        }
    }
    file.close();
}

bool verify_date(string date) {
    int day, month, year;
    char sep1, sep2;
    std::stringstream ss(date);
    if (ss >> day >> sep1 >> month >> sep2 >> year) {
        if (sep1 == '/' && sep2 == '/' && day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1990 && year <= 2023) {
            return true;
        }
    }
    return false;
}

void CListaCopil::Add()
{
    MyNamespace::smart("Configurator de copil");
    std::string nume, prenume, dataNastere;
    bool cuminteRau;
    std::vector<int> indexAdresa, indexCadouriDorite, indexCadouriPrimite;
    int cadouriDorite, cadouriPrimite, indexat;
    //nume
    cout << "Introdu nume copil: ";
    cin >> nume;
    //prenume
    cout << "Ce prenume are copilul?" << endl;
    cin >> prenume;
    //data nastere
    cout << "Pe ce data este nascut copilul? (sub forma DD/MM/YYYY) : ";
    cin >> dataNastere;
    while (!verify_date(dataNastere)) {
        cout << "Input invalid.Formatul datei trebuie sa fie DD/MM/YYYY.Introduceti din nou" << endl;
        cin >> dataNastere;
    }
    //cuminte/rau
    cout << "A fost cuminte sau rau?" << endl;
    string x;
    CListaAdresa p;
    cin >> x;
    while (x != "cuminte" && x != "rau") {
        cout << "Input invalid.Scrie cuminte sau rau." << endl;
        cin >> x;
    }
    cuminteRau = (x == "cuminte" ? 1 : 0);
    //adrese
    int r, k, z = 1;
    cout << "Cate adrese are copilul " << nume << "?( total adrese fisier sunt " << p.getNr() << ")" << endl;
    cin >> r;
    while (r > p.getNr() || r < 1) {
        cout << "Cate adrese are copilul " << nume << "?( total adrese fisier sunt " << p.getNr() << ")" << endl;
        cin >> r;
    }
    //fiecare adresa a copilului
    while (z <= r) {
        cout << "Care este adresa nr. " << z << " a copilului ?" << endl;
        for (auto& i : p.getListaAdrese())
            cout << i->getId() << ".Localitatea" << i->getLocalitate() << ",nr." << i->getNr() << ",Strada " << i->getStrada() << endl;
        z++;
        cin >> k;
        bool found = false;
        for (auto i : p.getListaAdrese()) {
            if (i->getId() == k) {
                found = true;
                break;
            }
        }
        if (found)
            indexAdresa.push_back(k);
        else {
            cout << "Adresa nu se afla in lista. Introduceti din nou" << endl;
            z--;
        }
    }
    //adresa actuala
    cout << "Care este adresa actuala a copilului ? " << endl;
    for (auto& i : p.getListaAdrese())
        cout << i->getId() << ". " << i->getLocalitate() << " " << i->getNr() << " " << i->getStrada() << endl;
    cin >> indexat;
    while (std::find(indexAdresa.begin(), indexAdresa.end(), indexat) == indexAdresa.end()) {
        cout << "Adresa nu se afla in lista adreselor copilului. Introduceti din nou" << endl;
        cin >> indexat;
    }
    CListaCadou y;
    //nr cadouri dorite
    cout << "Cate cadouri doreste copilul " << nume << "?\n(trebuie sa fie mai mic sau egal cu nr cadourilor existente in fisier adica <"<< y.getNr()<< ")" << endl;
    cin >> cadouriDorite;
    while (cadouriDorite > y.getNr() || cadouriDorite <= 0) {
        cout << "Introduceti un numar valid" << endl;
        cin >> cadouriDorite;
    }
    for (int i = 0; i < cadouriDorite; ++i) {
        for (auto& j : y.getListaCadou())
            cout << j->getId() << ". " << j->getDenumire() << " " << j->getCuloare() << endl;
        cin >> k;
        bool found = false;
        for (auto j : y.getListaCadou()) {
            if (j->getId() == k) {
                found = true;
                break;
            }
        }
        if (found)
            indexCadouriDorite.push_back(k);
        else {
            cout << "Cadoul nu se afla in lista. Introduceti din nou" << endl;
            i--;
        }
    }
    //nr cadouri primite
    cout << "Cate cadouri va primi copilul " << nume << "?" << endl;
    cin >> cadouriPrimite;
    while (cadouriPrimite > y.getNr() || cadouriPrimite <= 0) {
        cout << "Introduceti un numar valid" << endl;
        cin >> cadouriPrimite;
    }
    for (int i = 0; i < cadouriPrimite; ++i) {
        for (auto& j : y.getListaCadou())
            cout << j->getId() << ". " << j->getDenumire() << " " << j->getCuloare() << endl;
        cin >> k;
        bool found = false;
        for (auto j : y.getListaCadou()) {
            if (j->getId() == k) {
                found = true;
                break;
            }
        }
        if (found)
            indexCadouriPrimite.push_back(k);
        else {
            cout << "Cadoul nu se afla in lista. Introduceti din nou" << endl;
            i--;
        }
    }

    cout << "Copilul a fost adaugat cu succes in fisier!" << endl;
    // increment nrCopii
    nrCopii++;
    ofstream file;
    file.open("lista_copii.txt", ios::app);
    file << "\n"<< nume << " " << prenume << " " << dataNastere << " " << cuminteRau << " ";
    for (auto index : indexAdresa)
        file << index;
    file << " " << cadouriDorite << " ";
    for (auto index : indexCadouriDorite)
        file << index;
    file << " " << cadouriPrimite << " ";
    for (auto index : indexCadouriPrimite)
        file << index;
    file << " " << indexat;
    file.close();
    listaCopii.clear();
    nrCopii = 0;
    loadFile();
}

void CListaCopil::Delete() {
    MyNamespace::smart("Delete Copii");
    if (!listaCopii.empty()) {
        print();
        cout << "Introdu index copil pentru a sterge din lista: ";
        int option;
        cin >> option;
        while (option > getNr()) {
            cout << "Introduceti un numar valid" << endl;
            cin >> option;
        }
        listaCopii.erase(listaCopii.begin() + option - 1);
        nrCopii--;
        writeToFile(listaCopii);
        cout << "Copilul a fost sters cu succes in fisier!" << endl;
    }
    else {
        cout << "Nu este nici1 copil in lista de copii. Vei fi redirectionat catre meniul principal!";
        return;
    }
    listaCopii.clear();
    nrCopii = 0;
    loadFile();
}

void CListaCopil::Update() {
    MyNamespace::smart("Update copil");
    print();
    cout << "Ce copil vrei sa modifici? (1-" << getNr() << ")" << endl;
    int x;
    cin >> x;
    system("cls");
    if (!listaCopii.empty()) {
        int index = 1;
        for (auto& copil : listaCopii) {
            if (index == x) {
                int option[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
                cout <<option[0]<< ". Nume: " << copil->getNume() << endl;          
                cout <<option[1]<< ". Prenume: " << copil->getPrenume() << endl;
                cout <<option[2] << ". Data Nasterii: " << copil->getDataNastere() << endl;
                string l = copil->getCuminteRau() == 1 ? "cuminte" : "rau";
                cout << option[3]<< ". Cuminte sau Rau: " << l << endl;
                cout << option[4] << ". Nr adrese si adresele: ";
                for (auto index : copil->getIndexAdresa())
                    cout << index;
                cout << endl;
                cout << option[5] << ". Adresa actuala: " << copil->getAdresaCurenta() << endl;
                cout << option[6] << ". Cadourile dorite: " << copil->getNrCadouriDorite() << endl;
                CListaCadou y;
                std::vector<CCadou*> list = y.getListaCadou();
                for (auto index : copil->getIndexCadouriDorite()) {
                    for (auto j = list.begin(); j != list.end(); j++) {
                        int s = (*j)->getId();
                        if (s == index)
                            cout << (*j)->getDenumire() << " " << (*j)->getCuloare() << endl;
                    }
                }
                cout << endl;
                cout << option[7] << ". Cadourile primite: " << copil->getNrCadouriPrimite() << endl;
                for (auto& j : y.getListaCadou())
                    for (auto index : copil->getIndexCadouriPrimite())
                        if (j->getId() == index)
                            cout << j->getDenumire() << " " << j->getCuloare() << endl;
                cout << endl << endl << "Ce camp doresti sa modifici ?" << endl << "(introdu numarul): ";
                int k;
                cin >> k;
                for (auto& j : option) {
                    if (j == k) {//schimba nume
                        cout << "NEW\n";
                        if (k == 1) {
                            cout << "Introdu noul nume: ";
                            string a;
                            cin >> a;
                            copil->setNume(a);
                        }
                        else if (k == 2) {//schimba prenume
                            cout << "Introdu noul prenume: ";
                            string a;
                            cin >> a;
                            copil->setPrenume(a);
                        }
                        else if (k == 3) {//schimba data de nastere
                            cout << "Pe ce data este nascut copilul? (sub forma DD/MM/YYYY) : ";
                            string a;
                            cin >> a;
                            while (!verify_date(a)) {
                                cout << "Input invalid.Formatul datei trebuie sa fie DD/MM/YYYY.Introduceti din nou" << endl;
                                cin >> a;
                            }
                            copil->setDataNastere(a);
                        }
                        else if (k == 4) {//schimba daca a fost cuminte sau rau
                            cout << "A fost cuminte sau rau?" << endl;
                            string a;
                            cin >> a;
                            while (a != "cuminte" && a != "rau") {
                                cout << "Input invalid.Scrie cuminte sau rau." << endl;
                                cin >> x;
                            }
                            bool c = (a == "cuminte" ? 1 : 0);
                            copil->setCuminteRau(c);
                        }
                        else if (k == 5) {//schimba nr de adrese
                            std::vector<int> indexAdresa;
                            CListaAdresa p;
                            int r, k, z = 1;
                            cout << "Cate adrese are copilul " << copil->getNume() << "?( total adrese fisier sunt " << p.getNr() << ")" << endl;
                            cin >> r;
                            while (r > p.getNr() || r < 1) {
                                cout << "Cate adrese are copilul " << copil->getNume() << "?( total adrese fisier sunt " << p.getNr() << ")" << endl;
                                cin >> r;
                            }
                            //fiecare adresa a copilului
                            while (z <= r) {
                                cout << "Care este adresa nr. " << z << " a copilului ?" << endl;
                                for (auto& i : p.getListaAdrese())
                                    cout << i->getId() << ".Localitatea" << i->getLocalitate() << ",nr." << i->getNr() << ",Strada " << i->getStrada() << endl;
                                z++;
                                cin >> k;
                                bool found = false;
                                for (auto i : p.getListaAdrese()) {
                                    if (i->getId() == k) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found)
                                    indexAdresa.push_back(k);
                                else {
                                    cout << "Adresa nu se afla in lista. Introduceti din nou" << endl;
                                    z--;
                                }
                            }
                            copil->setIndexAdresa(indexAdresa);
                        }
                        else if (k == 6) {//schimba adresa actuala
                            CListaAdresa p;
                            int indexat;
                            cout << "Care este adresa actuala a copilului ? " << endl;
                            for (auto& i : p.getListaAdrese())
                                cout << i->getId() << ". " << i->getLocalitate() << " " << i->getNr() << " " << i->getStrada() << endl;
                            cin >> indexat;
                            while (std::find(copil->getIndexAdresa().begin(), copil->getIndexAdresa().end(), indexat) == copil->getIndexAdresa().end()) {
                                cout << "Adresa nu se afla in lista adreselor copilului. Introduceti din nou" << endl;
                                cin >> indexat;
                            }
                            copil->setAdresaCurenta(indexat);
                        }
                        else if (k == 7) {//cadouri dorite
                            CListaCadou y;
                            int cadouriDorite;
                            std::vector<int> indexCadouriDorite;
                            cout << "Cate cadouri doreste copilul " << copil->getNume() << "?\n(trebuie sa fie mai mic sau egal cu nr cadourilor existente in fisier adica <" << y.getNr() << ")" << endl;
                            cin >> cadouriDorite;
                            while (cadouriDorite > y.getNr() || cadouriDorite <= 0) {
                                cout << "Introduceti un numar valid" << endl;
                                cin >> cadouriDorite;
                            }
                            copil->setNrCadouriDorite(cadouriDorite);
                            for (int i = 0; i < cadouriDorite; ++i) {
                                for (auto& j : y.getListaCadou())
                                    cout << j->getId() << ". " << j->getDenumire() << " " << j->getCuloare() << endl;
                                cin >> k;
                                bool found = false;
                                for (auto j : y.getListaCadou()) {
                                    if (j->getId() == k) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found)
                                    indexCadouriDorite.push_back(k);
                                else {
                                    cout << "Cadoul nu se afla in lista. Introduceti din nou" << endl;
                                    i--;
                                }
                            }
                            copil->setIndexCadouriDorite(indexCadouriDorite);
                        }
                        else if (k == 8) {
                            //nr cadouri primite
                            CListaCadou y;
                            int cadouriPrimite;
                            std::vector<int> indexCadouriPrimite;
                            cout << "Cate cadouri va primi copilul " << copil->getNume() << "?" << endl;
                            cin >> cadouriPrimite;
                            while (cadouriPrimite > y.getNr() || cadouriPrimite <= 0) {
                                cout << "Introduceti un numar valid" << endl;
                                cin >> cadouriPrimite;
                            }
                            copil->setNrCadouriPrimite(cadouriPrimite);
                            for (int i = 0; i < cadouriPrimite; ++i) {
                                for (auto& j : y.getListaCadou())
                                    cout << j->getId() << ". " << j->getDenumire() << " " << j->getCuloare() << endl;
                                cin >> k;
                                bool found = false;
                                for (auto j : y.getListaCadou()) {
                                    if (j->getId() == k) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (found)
                                    indexCadouriPrimite.push_back(k);
                                else {
                                    cout << "Cadoul nu se afla in lista. Introduceti din nou" << endl;
                                    i--;
                                }
                            }
                            copil->setIndexCadouriPrimite(indexCadouriPrimite);
                        }
                        cout << "Campurile au fost schimbate cu succes!";
                        writeToFile(listaCopii);
                        break;
                    }
                }
            }
            index++;
        }
    }
    else {
        cout << "Nu este nici1 copil in lista de copii. Vei fi redirectionat catre meniul principal!";
        return;
    }
}

void CListaCopil::writeToFile(std::vector<CCopil*> listaCopii)
{
    ofstream file;
    file.open("lista_copii.txt", ios::trunc);
    for (auto copil : listaCopii)
    {
        file<<copil->getNume()<<" "<<copil->getPrenume()<<" "<<copil->getDataNastere()<<" "<<copil->getCuminteRau()<<" ";
        for(auto index:copil->getIndexAdresa())
            file<<index;
        file << " "<< copil->getNrCadouriDorite() << " ";
        for (auto index : copil->getIndexCadouriDorite())
            file << index;
        file << " ";
        file<<copil->getNrCadouriPrimite()<<" ";
        for(auto index:copil->getIndexCadouriPrimite())
            file<<index;
        file << " ";
        if (copil == listaCopii.back())
            file << copil->getAdresaCurenta();
        else
            file << copil->getAdresaCurenta() << "\n";
    }
    file.close();
}
