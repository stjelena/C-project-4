#pragma once
#include <exception>
using namespace std;

class GMinVrednost : public exception {
public:
	GMinVrednost() : exception("Greska: Vrednost igraca je manja od minimalne"
		"vrednosti potrebne da se igrac prikljuci timu") {}
};

class GNeodigranMec : public exception {
public:
	GNeodigranMec() : exception("Greska: Mec nije odigran!") {}
};