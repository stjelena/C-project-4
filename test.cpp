#include "Igrac.h"
#include "Tim.h"
#include "PrivilegovaniTim.h"
#include "Mec.h"

int main() {
	try {
		Igrac i1("Pera", 600);
		cout << i1 << endl;
		i1.promeniVr(true, 50);
		cout << i1;
		cout << endl;
		Igrac i2("Jeca", 500);
		cout << i2 << endl;
		i2.promeniVr(false, 20);
		cout << i2 << endl << endl;

		Tim t("najjaci", 3);
		t.prikljuciIgraca(i1, 55);
		t.prikljuciIgraca(i2, 66);
		cout << t;
		Tim t2("random", 6);
		Igrac i3("neko", 600);
		Igrac i4("misa", 1000);
		Igrac i5("cica", 500);
		Tim t3("najjaci", 3);
		t2.prikljuciIgraca(i3, 6);
		t2.prikljuciIgraca(i4, 8);
		t2.prikljuciIgraca(i5, 10);
		t3.prikljuciIgraca(i1, 55);
		t3.prikljuciIgraca(i2, 66);
		cout << endl << t2 << endl << t3;
		cout << endl << t.vrednost();
		cout << t[55];
		if (t == t3) cout << endl << "t2 i t3 su jednaki";
		else cout << "nisu jednaki";
		if (t2 == t3) cout << endl << "t2 i t3 su jednaki";
		else cout << "nisu jednaki" << endl << t.brIgraca() << endl;
		//t.~Tim();
		//cout << t;
		PrivilegovaniTim pt1("privilegovani", 2, 600);
		pt1.prikljuciIgraca(i3, 3);
		cout << pt1;
		//pt1.prikljuciIgraca(i5, 5);
		pt1.prikljuciIgraca(i4, 9);
		cout << pt1 << endl << endl;

		Mec mec1(&t, &pt1);
		cout << mec1 << endl;
		mec1.odigrajMec();
		cout << mec1 << endl << endl;
		cout << mec1.dohvPoene();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}