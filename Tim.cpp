#include "Tim.h"

void Tim::kopiraj(const Tim& t)
{
	naziv = t.naziv;
	max = t.max;
	br = t.br;
	prvi = posl = tek = nullptr;
	for (t.tek = t.prvi; t.tek; t.tek = t.tek->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(tek->i, tek->pozicija);
	}
}

void Tim::premesti(Tim& t)
{
	naziv = t.naziv;
	max = t.max;
	br = t.br;
	prvi = t.prvi;
	posl = t.posl;
	tek = t.tek;
	t.prvi = t.posl = t.tek = nullptr;
}

void Tim::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = nullptr;
}

Tim& Tim::operator=(const Tim& t)
{
	if (this != &t) {
		brisi();
		kopiraj(t);
	}
	return *this;
}

Tim& Tim::operator=(Tim&& t)
{
	if (this != &t) {
		brisi();
		premesti(t);
	}
	return *this;
}

void Tim::prikljuciIgraca(Igrac& i, int pozicija)
{
	br++;
	if (br <= max) { //moze i exception ali nije zahtevano u zad
		posl = (!prvi ? prvi : posl->sled) = new Elem(i, pozicija);
	}
}

Igrac& Tim::operator[](int pozicija)
{
	tek = prvi;
	while (tek) {
		if (tek->pozicija == pozicija) return tek->i;
		else tek = tek->sled;
	}
}

const Igrac& Tim::operator[](int pozicija) const
{
	tek = prvi;
	while (tek) {
		if (tek->pozicija == pozicija) return tek->i;
		else tek = tek->sled;
	}
}

int Tim::vrednost()
{
	int n = 0;
	tek = prvi;
	while (tek) {
		n += tek->i.dohvVrednost();
		tek = tek->sled;
	}
	return (int)(n / br);
}

void Tim::promeniVr(bool povecaj, double procenat)
{
	for (tek = prvi; tek; tek = tek->sled) {
		tek->i.promeniVr(povecaj, procenat);
	}
}

bool operator==(const Tim& t1, const Tim& t2)
{
	t1.tek = t1.prvi;
	while(t1.tek) {
		t2.tek = t2.prvi;
		while(t2.tek) {
			if (t1.tek->i == t2.tek->i && t1.tek->pozicija == t2.tek->pozicija) {
				t1.tek = t1.tek->sled;
				t2.tek = t2.prvi;
			}
			else t2.tek = t2.tek->sled;
			if (!t2.tek) return false;
			if (!t1.tek) break;
		}
	}
	return (t1.max == t2.max && t1.naziv == t2.naziv);
}

ostream& operator<<(ostream& it, const Tim& t)
{
	int i = 0;
	it << t.naziv << "[";
	for (t.tek = t.prvi; t.tek; t.tek = t.tek->sled) {
		i++;
		it << t.tek->i;
		if (i != t.br) it << ", ";
	}
	it << "]";
	return it;
}
