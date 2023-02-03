#pragma once
#include <vector>
#include "CCadou.h"
#include "IModel.h"

class CListaCadou : public IModel
{
	int nrCadouri;
	std::vector<CCadou*> listaCadouri;
public:
	CListaCadou();
	virtual ~CListaCadou() { nrCadouri = 0; listaCadouri.clear(); }
	void print();
	void loadFile();
	int getNr() { return nrCadouri; }
	std::vector<CCadou*> getListaCadou() { return listaCadouri; }
	void Add();
	void Delete();
	void Update();
	void writeFile();
};

