#pragma once
#include "CUser.h"
class Spiridus : public CUser
{
	int nrSpiridusi;
public:
	Spiridus() : CUser(), nrSpiridusi(0) { }
	void login();
	void inregistrare();
};