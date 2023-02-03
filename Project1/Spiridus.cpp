#include "Spiridus.h"
#include <fstream>
#include <vector>
#include <tuple>
#include <conio.h>
#include "MyException.h"
#include "MyNamespace.h"

std::vector<tuple<int, string, string>> loadFile() {
    ifstream file("spiridusi.txt");
    vector<tuple<int, string, string>> spiridusi;
    int id;
    string username, password;
    while (file >> id >> username >> password)
        spiridusi.push_back(std::make_tuple(id, username, password));
    file.close();
    return spiridusi;
}

void Spiridus::login() {
    auto spiridusi = loadFile();
    nrSpiridusi = spiridusi.size();
    string entered_username, entered_password;
    cout << "Auth" << endl;
    cout << "Introdu numele spiridusului: ";
    cin >> entered_username;
    cout << "Introdu parola spiridusului: ";
    char ch = _getch();
    while (ch != '\r')
    {
        if (ch == '\b') {
            if (!entered_password.empty()) {
                entered_password.pop_back();
                cout << "\b \b";
            }
        }
        else {
            entered_password += ch;
            cout << '*';
        }
        ch = _getch();
    }
    cout << endl;
    bool found = false;
    for (auto spiridus : spiridusi)
        if (get<1>(spiridus) == entered_username && get<2>(spiridus) == entered_password) {
            this->getLogger()->log("Spiridus " + entered_username + " autentificat.");
            int option = 0, choice = 0;
            do
            {
                CListaCadou* cadouri = new CListaCadou();
                CListaComponente* componente = new CListaComponente();
                jump:
                MyNamespace::print_menuSpiridus(entered_username);
                cin >> option;
                printf("\n\n");
                switch (option)
                {
                case 1://modifica lista cadouri
                    MyNamespace::AddDelete_menu("cadou");
                    cin >> choice;
                    switch (choice)
                    {
                    case 1://adauga cadou
                        cadouri->Add();
                        this->getLogger()->log("Spiridusul " + entered_username + " a adaugat un cadou nou.");
                        break;
                    case 2://delete cadou
                        cadouri->Delete();
                        this->getLogger()->log("Spiridusul " + entered_username + " a sters un cadou.");
                        break;
                    case 3://update cadou
                        cadouri->Update();
                        this->getLogger()->log("Spiridusul " + entered_username + " a facut update unui cadou.");
                        break;
                    case 4://disp cadou
                        cadouri->print();
                        break;
                    case 5://inapoi
                        goto jump;
                        break;
                    case 6://exit
                        this->getLogger()->log("Spiridusul " + entered_username + " a iesit din aplicatie.");
                        exit(0);
                        break;
                    }
                    break;
                case 2:
                    MyNamespace::AddDelete_menu("componente");
                    cin >> choice;
                    switch (choice)
                    {
                        case 1://add comp
                            componente->Add();
                            this->getLogger()->log("Spiridusul " + entered_username + " a adaugat o componenta nou.");
                            break;
                        case 2://delete comp
                            componente->Delete();
                            this->getLogger()->log("Spiridusul " + entered_username + " a sters o componenta.");
                            break;
                        case 3://update comp
                            componente->Update();
                            this->getLogger()->log("Spiridusul " + entered_username + " a facut update unei componente.");
                            break;
                        case 4://disp cadou
                            cout << componente;
                            break;
                        case 5://inapoi
                            goto jump;
                            break;
                        case 6://exit
                            this->getLogger()->log("Spiridusul " + entered_username + " a iesit din aplicatie.");
                            exit(0);
                            break;
                    }
                    break;
                case 3://inapoi
                    return;
                    break;
                case 4://exit
                    this->getLogger()->log("Spiridusul " + entered_username + " a iesit.");
                    exit(0);
                    break;
                }
                printf("\n\nApasa spatiu pentru a continua:");
                while (_getch() != ' ') {}

            } while (option != '0');
        }
    if (!found) {
        this->getLogger()->log("Cineva cu numele "+ entered_username + " a esuat in autentificare, ca spiridus.");
        throw new MyException(2, "Autentificare esuata. Verifica numele si parola.\n");
    }
}

void Spiridus::inregistrare()
{
    vector<tuple<int, string, string>> spiridusi = loadFile();
    nrSpiridusi = spiridusi.size() + 1;
    string entered_username, entered_password;
    cout << "Introdu numele pentru noul spiridus: ";
    cin >> entered_username;
    bool found = false;
    for (auto spiridus : spiridusi)
        if (get<1>(spiridus) == entered_username) {
            found = true;
            this->getLogger()->log("Cineva incearca sa creeze un cont cu numele "+entered_username+" dar l-am impiedicat");
            throw new MyException(1, "Exista deja un spiridus cu acest nume. Inregistrarea nu poate fi efectuata.\n");
            break;
        }
    if (!found) {
        cout << "Introdu parola pentru noul spiridus: ";
        char ch = _getch();
        while (ch != '\r')
        {
            if (ch == '\b') {
                if (!entered_password.empty()) {
                    entered_password.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                entered_password += ch;
                cout << '*';
            }
            ch = _getch();
        }
        setUsername(entered_username);
        setPassword(entered_password);
        ofstream file("spiridusi.txt", ios::app);
        setId(nrSpiridusi);
        file << getId() << " " << getUsername() << " " << getPassword() << endl;
        file.close();
        this->getLogger()->log("Spiridusul " + getUsername() + " a fost inregistrat.");
        cout << endl<<"Contul spiridusului a fost creat cu succes!" << endl;
    }
}