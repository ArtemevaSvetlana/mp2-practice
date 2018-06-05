#pragma once
#include <string>
#include <cstdlib>
#include  <cctype>
#include <iostream>

using namespace std;

class Monom {

public:
	double cf; //коэффициент (может быть отрицательный)
	unsigned int abc; //степени 

	Monom();
	Monom(double d, unsigned int st);
	void SetCf(double c) { cf = c; }
	void SetIndex(int a) { abc = a; }
	unsigned int GetIndex(void) { return abc; }
	const Monom& operator=(const Monom &m);
	Monom& operator+(const Monom &m);
	Monom& operator*(const double &d);
	Monom& operator*(const Monom &m);
	bool operator==(const Monom &m) const;
	bool operator!=(const Monom &m) const;
	bool operator<(const Monom &m) const;
	friend ostream& operator<<(ostream& os, const Monom& m)
	{
		Monom Mon;
		Mon = m;
		int stx = (int)Mon.abc / 100;
		int sty = (int)(Mon.abc / 10 - stx * 10);
		int stz = (int)(Mon.abc % 10);

		if (Mon.cf==0)
			cout<<"0"<<endl;
		else
		{
			if ( Mon.cf==1 && stx==0 && sty==0 && stz==0)
				cout<<Mon.cf;
			else if (Mon.cf!=1)
				cout<<Mon.cf;
			
			if (stx!=0)
			{
				if (stx==1)
					cout<<"x";
				else
					cout<<"x^"<<stx;
			}

			if (sty!=0)
			{
				if (sty==1)
					cout<<"y";
				else
					cout<<"y^"<<sty;
			}

			if (stz!=0)
			{
				if (stz==1)
					cout<<"z"<<stz;
				else 
					cout<<"z^";
			}
		}
		return os;
	};
};