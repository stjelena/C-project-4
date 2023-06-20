#pragma once
#include "Par.h"
#include "Tim.h"
#include "PrivilegovaniTim.h"

enum ISHOD { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };

class Mec {
	Par<Tim> par;
	ISHOD ishod;
	bool odigran = false;
	Par<int> poeni = *new Par<int>(new int(0), new int(0));
public:
	Mec(Tim* t1, Tim* t2) : par(t1, t2) {}
	
	void odigrajMec();

	bool odigranMec() { return odigran; }

	Par<int>& dohvPoene();

	friend ostream& operator<<(ostream& it, const Mec& m);
};