#pragma once
#include "IModel.h"
#include "CListaAdresa.h"
#include "CListaComponente.h"
#include "CListaCadou.h"
#include "CListaCopil.h"

namespace MyNamespace
{
    enum class TipModel { TipListaAdresa, TipListaComponente, TipListaCadou, TipListaCopii };

    inline IModel* getModel (TipModel tmp) {
        switch (tmp) {
        case TipModel::TipListaAdresa:
            return new CListaAdresa();
            break;
        case TipModel::TipListaComponente:
            return new CListaComponente();
            break;
        case TipModel::TipListaCadou:
            return new CListaCadou();
            break;
        case TipModel::TipListaCopii:
            return new CListaCopil();
            break;
        }
    }
    inline void smart(string x) {
        system("cls");
        printf("##########################################################\n");
        cout<<"                         "<<x<<"                         \n";
        printf("##########################################################\n");
    }

    inline void print_menu()
    {
        smart("MENU");

        cout << "Alegeti o optiune:" << endl;
        cout << "1. Inregistrare spiridus." << endl;
        cout << "2. Autentificare spiridus." << endl;
        cout << "3. Inregistrare Mos Craciun." << endl;
        cout << "4. Autentificare Mos Craciun." << endl;
        cout << "5. Iesire." << endl;
        printf("----------------------------------------------------------\n");
        printf("Introduceti optiunea dorita(1-5): ");
    }

    inline void print_menuMos(string x) {
        smart("Bine ai venit Mosule " + x + "!");
        cout << "Alegeti o optiune:" << endl;
        cout << "1. Modifica lista de copii." << endl;
        cout << "2. Modifica lista de cadouri." << endl;
        cout << "3. Delogare." << endl;
        cout << "4. Iesire." << endl;
        printf("----------------------------------------------------------\n");
        printf("Introduceti optiunea dorita(1-4): ");
    }

    inline void print_menuSpiridus(string x) {
        system("cls");
        cout << "Spiridusule " << x << endl;
        cout << "Alege o optiune:" << endl;
        cout << "1. Modifica lista de cadouri." << endl;
        cout << "2. Modifica lista de componente." << endl;
        cout << "3. Delogare." << endl;
        cout << "4. Iesire." << endl;
        printf("----------------------------------------------------------\n");
        printf("Introduceti optiunea dorita(1-3): ");
    }
    
    inline void AddDelete_menu(string x) {
        system("cls");
        cout << "1. Adauga "<<x<< " in lista." << endl;
        cout << "2. Sterge " << x << " din lista." << endl;
        cout << "3. Update lista " << x << "." << endl;
        cout << "4. Afiseaza lista " << x << ". " << endl;
        cout << "5. Inapoi." << endl;
        cout << "6. Exit." << endl;
        printf("----------------------------------------------------------\n");
        printf("Introduceti optiunea dorita(1-6): ");
    }
};

