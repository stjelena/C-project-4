#pragma once
#include <iostream>
using namespace std;//da li su potrebni konstruktori??

template<typename T>
class Par {
	T* t1,* t2;
public:
	Par(T* tt1, T* tt2) : t1(tt1), t2(tt2) {}

	/*Par(const Par& p) = default;
	Par& operator=(const Par& p) = default;
	~Par() {
		delete[] t1;
		delete[] t2;
	}*/

	T* dohvt1() const { return t1; }
	T* dohvt2() const { return t2; }

	void postavit1(T* tt) { t1 = tt; }
	void postavit2(T* tt) { t2 = tt; }

	friend bool operator==(const Par& p1, const Par& p2) {
		return (p1.dohvt1() == p2.dohvt1() && p1.dohvt2() == p2.dohvt2());
	}

	friend ostream& operator<<(ostream& it, const Par& p) {
		return it << "[" << *(p.dohvt1()) << "," << *(p.dohvt2()) << "]";
	}
};




