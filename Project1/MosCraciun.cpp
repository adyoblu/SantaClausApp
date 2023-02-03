#include "MosCraciun.h"
#include <fstream>
#include "MyNamespace.h"
#include "MyException.h"
#include "CListaCadou.h"
#include "CListaCopil.h"
#include <conio.h>
#include "MyNamespace.h"

void MosCraciun::login()
{
    ifstream file1("mosCraciun.txt");
    if (!file1.is_open()) {
        this->getLogger()->log("Autentificarea a esuat fiindca nu exista un cont de mos craciun.");
        throw new MyException(3, "Nu te poti autentifica Mos Craciun fiindca nu exista vreun cont creeat.\n");
    }
    else
    {
        int id;
        std::string username, password;
        if (file1 >> id >> username >> password)
        {
            cout << "Auth" << endl;
            cout << "Introdu username pentru mosCraciun: ";
            string x; cin >> x;
            cout << "Introdu password pentru mosCraciun: ";
            string y;
            char ch = _getch();
            while (ch != '\r')
            {
                if (ch == '\b') {
                    if (!y.empty()) {
                        y.pop_back();
                        cout << "\b \b";
                    }
                }
                else {
                    y += ch;
                    cout << '*';
                }
                ch = _getch();
            }
            cout << endl;
            if (username == x && password == y)
            {
                this->getLogger()->log("Mos " + username + " autentificat.");
                int option = 0, choice = 0;
                CListaCopil* Lcopii = new CListaCopil();
                CListaCadou* Lcadouri = new CListaCadou();
                do
                {
                    /*modele.push_back(MyNamespace::getModel(MyNamespace::TipModel::TipListaCopii));
                    modele.push_back(MyNamespace::getModel(MyNamespace::TipModel::TipListaCadou));*/
                jump:
                    MyNamespace::print_menuMos(username);
                    cin >> option;
                    printf("\n\n");
                    switch (option)
                    {
                        case 1://modifica lista copii
                            MyNamespace::AddDelete_menu("copii");
                            cin >> choice;
                            switch (choice)
                            {
                                case 1://add copil
                                    Lcopii->Add();
                                    this->getLogger()->log("Copil adaugat de mos craciun la fisierul lista_copii.txt.");
                                    break;
                                case 2://delete copil
                                    Lcopii->Delete();
                                    this->getLogger()->log("Copil sters de mos craciun la fisierul lista_copii.txt.");
                                    break;
                                case 3://modify field copil
                                    Lcopii->Update();
                                    this->getLogger()->log("Copil updatat de mos craciun la fisierul lista_copii.txt.");
                                    break;
                                case 4://afiseaza
                                    Lcopii->print();
                                    break;
                                case 5:
                                    goto jump;
                                    break;
                                case 6:
                                    this->getLogger()->log("Mos " + username + " a iesit din aplicatie.");
                                    exit(0);
                                    break;
                            }
                            break;
                        case 2://modifica lista cadouri
                            MyNamespace::AddDelete_menu("cadouri");
                            cin >> choice;
                            switch (choice)
                            {
                            case 1://add copil
                                Lcadouri->Add();
                                this->getLogger()->log("Cadou adaugat de mos craciun la fisierul lista_cadouri.txt.");
                                break;
                            case 2://delete copil
                                Lcadouri->Delete();
                                this->getLogger()->log("Cadou sters de mos craciun la fisierul lista_cadouri.txt.");
                                break;
                            case 3://modify field copil
                                Lcadouri->Update();
                                this->getLogger()->log("Cadou updatat de mos craciun la fisierul lista_cadouri.txt.");
                                break;
                            case 4://afiseaza
                                Lcadouri->print();
                                break;
                            case 5:
                                goto jump;
                                break;
                            case 6:
                                this->getLogger()->log("Mosul a iesit din aplicatie.");
                                exit(0);
                                break;
                            }
                            break;
                        case 3:
                            return;
                            break;
                        case 4:
                            this->getLogger()->log("Mosul a iesit din aplicatie.");
                            exit(0);
                    }
                    printf("\n\nApasa spatiu pentru a continua:");
                    while (_getch() != ' ') {}
                } while (option != '0');
            }
            else {
                this->getLogger()->log("Autentificare mos cu esec.");
                throw new MyException(2, "Acest cont nu exista!\n");
            }
        }
        file1.close();
    }
}

void MosCraciun::inregistrare() 
{
    ifstream file1("mosCraciun.txt");

    if (!file1.is_open()) {
        string x;
        cout << "Introdu username pentru mosCraciun: ";
        cin >> x;
        setUsername(x);
        cout << "Introdu password pentru mosCraciun: ";
        x.clear();
        char ch = _getch();
        while (ch != '\r')
        {
            if (ch == '\b') {
                if (!x.empty()) {
                    x.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                x += ch;
                cout << '*';
            }
            ch = _getch();
        }
        setPassword(x);
        ofstream file("mosCraciun.txt");
        file << getId() << " " << getUsername() << " " << getPassword() << endl;
        this->getLogger()->log("Mos craciun "+ getUsername() + " inregistrat.");
        file.close();
    }
    else {
        file1.close();
        this->getLogger()->log("Un user a incercat sa creeze un alt mos craciun dar a esuat.");
        throw new MyException(1, "Crearea de inca 1 Mos Craciun este imposibila.\n");
    }
}