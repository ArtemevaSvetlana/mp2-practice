#include "polinom.h"
#include "ringlist.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
		
	bool flag=true;
	string s;
	int k;
	Polinom Res, Zero;
	int m=-1;

	cout << "������� �������. �������, �� ������ ������������ ������ ����� x,y,z, ��� �������� � ������ ����������� ��������:\n";
	getline(cin, s);
	Polinom P(s);
    cout << "�������� ��������:"<<endl;
	cout<<"1 - �������� �� ���������"<<endl;
	cout<<"2 - �������� �� �������"<<endl;
	cout<<"3 - ������� � ���������" << endl;
	cout<<"4 - ��������� ���������"<< endl;
	cin >> k;
	cin.ignore(2, '\n');

	if (k!=4)
	{		
		cout<<"f1=";
		cout<<P<<endl;
		
		switch (k)
		{
			case 1:
			{
				double d;
				cout << "������� ����������� ��������: " << endl;
				cin >> d;
				cout<<"c="<<d<<endl;
				cout<<"c*f1=";
				Res = P*d;
				
				break;
			}
			case 2:
			{
				string s1;
				cout << "������� ������ �������: " << endl;
				getline(cin, s1);
				Polinom P1(s1);
				cout<<"f2="<<P1<< endl;
				Res = P*P1;
				cout<<"f1*f2=";
				break;
			}
			case 3: 
			{
				string s2;
				cout << "������� ������ �������: " << endl;
				getline(cin, s2);
				Polinom P2(s2);
				cout<<"f2="<<P2<< endl;
				Res = P + P2;
				cout<<"f1+f2=";		
				break;
			}
		}
		cout<<Res<<endl;

	}
	return 0;
}