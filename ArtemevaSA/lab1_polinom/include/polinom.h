#pragma once

#include <iostream>
#include "monom.h"
#include "ringlist.h"

using namespace std;

class Polinom {
	string s;
	RingList<Monom> monoms;
public:
	Polinom() {};
	~Polinom() {};
	Polinom(const string &str);
	Polinom(const Polinom &p1);


	Polinom operator+(const Polinom &p1);
	Polinom operator*(const Polinom &p1);
	Polinom operator*(const double &d);
	const Polinom& operator=(const Polinom &p1);
	friend std::ostream& operator<<(std::ostream &ostr, const Polinom &pm);	
};