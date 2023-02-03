#include <iostream>
#include "CListaCopil.h"
#include "MyException.h"
#include <conio.h>
#include "MyNamespace.h"
#include "MosCraciun.h"
#include "Spiridus.h"
#include "CListaAdresa.h"
#include "CListaCadou.h"
#include "CListaComponente.h"

int main() {
    std::vector<Spiridus*> x;
    std::vector<MosCraciun*> y;
    int option = 0;
	do
	{
		MyNamespace::print_menu();
        if (!(std::cin >> option) || option < 1 || option > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
		printf("\n\n");
        switch(option)
        {
            case 1://inregistrare spiridus
                try {
                    system("cls");
                    x.push_back(new Spiridus());
                    x.back()->inregistrare();
                }
                catch (MyException* exceptie) {
                    exceptie->print();
                }
                catch (...) {
                    std::cout << "Exceptie intalnita" << std::endl;
                }
                break;
            case 2://autentificare spiridus
                try{
                    system("cls");
                    x.push_back(new Spiridus());
                    x.back()->login();
                }
                catch (MyException* exceptie) {
                    exceptie->print();
                }
                catch (...) {
                    std::cout << "Exceptie intalnita" << std::endl;
                }
                break;
            case 3://inregistrare mos craciun
                try{
                    system("cls");
                    y.push_back(new MosCraciun());
                    y.back()->inregistrare();
                }
                catch (MyException* exceptie) {
                    exceptie->print();
                }
                catch (...) {
                    std::cout << "Exceptie intalnita" << std::endl;
                }
                break;
            case 4://autentificare mos craciun
                try{
                    system("cls");
                    y.push_back(new MosCraciun());
                    y.back()->login();
                }
                catch (MyException* exceptie) {
                    exceptie->print();
                }
                catch (const std::exception& e)
                {
                    std::cout << "Caught " << e.what();
                }
                catch (...) {
                    std::cout << "Exceptie intalnita" << std::endl;
                }
                break;
            case 5://iesire
                exit(0);
                break;
        }
		printf("\n\nApasa space pentru a continua:");
		while (_getch() != ' ') {}

	} while (option != '0');
    return 0;
}