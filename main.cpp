#include "Greske.h"
#include "Igrac.h"
#include "Mec.h"
#include "Par.h"
#include "PrivilegovaniTim.h"
#include "Tim.h"

int main() {
	try {
		Igrac i1("Nemanja Bjelica", 2000), i2("Bogdan Bogdanovic", 3000),
			i3("Boban Marjanovic", 2500), i4("Nikola Jokic", 4000), i5("Aleksej Pokusevski", 2000);
		//cout << i1;
		Tim t1("Reprezentacija Srbije", 20);
		t1.prikljuciIgraca(i1, 5);
		t1.prikljuciIgraca(i2, 10);
		t1.prikljuciIgraca(i3, 15);
		t1.prikljuciIgraca(i4, 23);
		t1.prikljuciIgraca(i5, 6);
		cout << t1 << endl;

		Igrac i11("Vasilije Micic", 1000);
		Tim t2("Turska", 5);
		t2.prikljuciIgraca(i1, 5);

		//cout << t1[5];
		Igrac i21("Milos Teodosic", 2000), i22("Nikola Kalinic", 1500), i23("Nikola Radicevic", 2500),
			i33("Uros Lukovic", 1000);
		Tim t3("Srbija", 5);
		t3.prikljuciIgraca(i21, 10);
		t3.prikljuciIgraca(i22, 11);
		t3.prikljuciIgraca(i23, 15);
		t3.prikljuciIgraca(i33, 20);
		cout << t2 << endl << t3;

		PrivilegovaniTim t4("Favoriti", 5, 2000);
		t4.prikljuciIgraca(i2, 5);
		t4.prikljuciIgraca(i3, 10);
		t4.prikljuciIgraca(i4, 11);
		//t4.prikljuciIgraca(i22, 60); throw exception
		cout << endl << t4 << endl << endl;

		Mec derbi(&t1, &t4);
		cout << derbi << endl;
		derbi.odigrajMec();
		cout << "DOMACIN: " << t1.vrednost() << "   GOST: " << t4.vrednost() << endl << endl;
		cout << derbi << "POENI: " << derbi.dohvPoene();
		cout << endl << "Igrac iz t4 na poziciji 10: " << t4[10] << endl << endl;
		
		Mec mec2(&t2, &t3);
		cout << mec2;
		mec2.odigrajMec();
		if (mec2.odigranMec()) cout << "ODIGRAN MEC: " << endl << mec2;
		cout << "DOMACIN: " << t2.vrednost() << "    GOST: " << t3.vrednost() << endl <<
			"POENI: " << mec2.dohvPoene() << endl << endl;

		Mec mec3(&t2, &t1);
		cout << mec3;
		mec3.odigrajMec();
		if (mec3.odigranMec()) cout << "ODIGRAN MEC: " << endl << mec3;
		cout << "DOMACIN: " << t2.vrednost() << "    GOST: " << t1.vrednost() << endl <<
			"POENI: " << mec3.dohvPoene() << endl << endl;
 	}
	catch (exception& e) {
		cout << endl << e.what() << endl;
	}
}