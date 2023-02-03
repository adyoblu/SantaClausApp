#pragma once
#include "CComponenta.h"
#include "IModel.h"

class CListaComponente : public IModel
{
	int nrComponente;
	std::vector<CComponenta*> listaComponente;
public:
	CListaComponente();
	void print();
	void loadFile();
	int getNr() { return nrComponente; }
	std::vector<CComponenta*> getListaComponente() { return listaComponente; }
	void Add();
	void Delete();
	void Update();
	friend std::ostream& operator<<(std::ostream& out, CListaComponente*& y);
	void writeFile();
};

