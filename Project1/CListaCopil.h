#pragma once
#include "CCopil.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CCadou.h"
#include "MyException.h"
#include "IModel.h"

class CListaCopil : public IModel
{
    int nrCopii;
    string numeLista;
    std::vector<CCopil*> listaCopii;
public:
	// constructor implicit
    CListaCopil();
    CListaCopil(CListaCopil&& other) noexcept : nrCopii(other.nrCopii), numeLista(std::move(other.numeLista)), listaCopii(std::move(other.listaCopii))
    {
        other.nrCopii = 0;
        other.listaCopii.clear();
    }
    // destructor
    virtual ~CListaCopil() { listaCopii.clear(); nrCopii = 0; numeLista.clear(); }
    // getter
    std::vector<CCopil*> getListaCopii() const {
        return listaCopii;
    }
    void print();
    void loadFile();
    int getNr() { return nrCopii; }
    void Add();
    void Delete();
    void Update();
    void writeToFile(std::vector<CCopil*>);
};