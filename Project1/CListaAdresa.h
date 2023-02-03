#pragma once
#include <vector>
#include "CAdresa.h"
#include "IModel.h"

class CListaAdresa : public IModel
{
	int nrAdrese;
	std::vector<CAdresa*> listaAdrese;
public:
	CListaAdresa();
	virtual ~CListaAdresa() { nrAdrese = 0; listaAdrese.clear(); }
	void print();
	void loadFile();
	int getNr() { return nrAdrese; }
	std::vector<CAdresa*> getListaAdrese() { return listaAdrese; }
	void Add() {}
	void Delete() {}
	void Update() {}
};