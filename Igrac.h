#pragma once
#include <string>
#include <iostream>
using namespace std;

class Igrac {
	string ime;
	int vrednost;
public:
	Igrac(string i, int v = 1000) : ime(i), vrednost(v) {}

	string dohvIme() const { return ime; }
	int dohvVrednost() const { return vrednost; }

	void promeniVr(bool povecaj, double procenat);

	friend bool operator==(const Igrac& i1, const Igrac& i2);

	friend ostream& operator<<(ostream& it, const Igrac& i);
};