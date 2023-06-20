#pragma once
#include "Igrac.h"

class Tim {
protected:
	string naziv;
	int max;
	int br = 0;
	struct Elem {
		Igrac& i;
		int pozicija;
		Elem* sled = nullptr;

		Elem(Igrac& ii, int poz) : i(ii), pozicija(poz) {}
	};
	Elem* prvi = nullptr, * posl = nullptr;
	mutable Elem* tek = nullptr;

	void kopiraj(const Tim& t);
	void premesti(Tim& t);
	void brisi();
public:
	Tim(string n, int m) : naziv(n), max(m) {}

	Tim(const Tim& t) {
		kopiraj(t);
	}
	Tim(Tim&& t) {
		premesti(t);
	}
	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&& t);
	~Tim() { brisi(); }

	virtual void prikljuciIgraca(Igrac& i, int pozicija);

	int brIgraca() const { return br; }

	Igrac& operator[](int pozicija);
	const Igrac& operator[](int pozicija)const;

	int vrednost();

	friend bool operator==(const Tim& t1, const Tim& t2);

	friend ostream& operator<<(ostream& it, const Tim& t);

	void promeniVr(bool povecaj, double procenat);
};