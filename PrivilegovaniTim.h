#pragma once
#include "Tim.h"
#include "Greske.h"

class PrivilegovaniTim : public Tim {
	int minvrednost;
public:
	PrivilegovaniTim(string n, int m, int mv) : Tim(n, m), minvrednost(mv) {}

	PrivilegovaniTim(const PrivilegovaniTim& pt) : Tim(pt) { this->minvrednost = pt.minvrednost; }
	PrivilegovaniTim(PrivilegovaniTim&& pt) : Tim(pt) { this->minvrednost = pt.minvrednost; }

	void prikljuciIgraca(Igrac& i, int pozicija) override;

	friend ostream& operator<<(ostream& it, const PrivilegovaniTim& pt);
};
