#include "Mec.h"

void Mec::odigrajMec()
{
	poeni.postavit1(new int(0));
	poeni.postavit1(new int(0));
	if (par.dohvt1()->vrednost() == par.dohvt2()->vrednost()) {
		ishod = NERESENO;
		poeni.postavit1(new int(1));
		poeni.postavit1(new int(1));
	}
	else if (par.dohvt1()->vrednost() > par.dohvt2()->vrednost()) {
		ishod = POBEDA_DOMACIN;
		par.dohvt1()->promeniVr(true, 10);
		par.dohvt2()->promeniVr(false, 10);
		poeni.postavit1(new int(3));
	}
	else {
		ishod = POBEDA_GOST;
		par.dohvt2()->promeniVr(true, 10);
		par.dohvt1()->promeniVr(false, 10);
		poeni.postavit2(new int(3));
	}
	odigran = true;
}

Par<int>& Mec::dohvPoene()
{
	if (!odigran) throw GNeodigranMec();
	return poeni;
}

ostream& operator<<(ostream& it, const Mec& m)
{
	string strIshod[]{ "POBEDA_DOMACIN", "NERESENO", "POBEDA_GOST" };
	it << "~MEC~" << endl << "Timovi: " << m.par << endl;
	if (m.odigran) it << "Ishod: " << strIshod[m.ishod] << endl;
	else it << "Mec nije odigran!" << endl;
	return it;
}
