#include "Igrac.h"

void Igrac::promeniVr(bool povecaj, double procenat)
{
	//true - povecaj
	//false - smanji
	double povecanje = vrednost * (1 + procenat / 100);
	double smanjenje = vrednost * (1 - procenat / 100);
	if (povecaj) vrednost = int(povecanje);
	else vrednost = int(smanjenje);
}

bool operator==(const Igrac& i1, const Igrac& i2)
{
	return i1.ime == i2.ime && i1.vrednost == i2.vrednost;
}

ostream& operator<<(ostream& it, const Igrac& i)
{
	return it << i.ime << "#" << i.vrednost;
}
