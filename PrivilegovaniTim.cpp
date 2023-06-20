#include "PrivilegovaniTim.h"

void PrivilegovaniTim::prikljuciIgraca(Igrac& i, int pozicija)
{
	if (i.dohvVrednost() < minvrednost) throw GMinVrednost();
	Tim::prikljuciIgraca(i, pozicija);
}

ostream& operator<<(ostream& it, const PrivilegovaniTim& pt)
{
	int i = 0;
	it << pt.naziv << "(" << pt.minvrednost << ")[";
	for (pt.tek = pt.prvi; pt.tek; pt.tek = pt.tek->sled) {
		i++;
		it << pt.tek->i;
		if (i != pt.br) it << ", ";
	}
	it << "]";
	return it;
}
