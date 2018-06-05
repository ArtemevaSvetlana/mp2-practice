#pragma once
#include "graph.h"
//#include "dheap_sort.h"
#include "kraskal.h"


using namespace std;


int main() 
{
	setlocale(LC_ALL, "Russian");

	int n,m;
	cout<<"	�������� ��������"<<endl;
	cout<<endl;
	cout << "������� ����� ������ � �����:" << endl;
	cin >> n;
	cout << "������� ����� ����� � �����:" << endl;
	cin >> m;
	Edge* E = new Edge[m];

	int l = 0;// ������ �� ������� �����
	for (int i = 0; i < (n-1); i++)
	{
		cout << "������� ���� ���� �����, ����������� ������� "<< i << endl;
		for (int j = i+1; j < n; j++)
		{
			float w;
			cout << " � �������� " << j << ": ";
			cin >> w;
			cout << endl;
			if (w != 0) 
			{
				Edge tmp(i, j, w);
				E[l] = tmp;
				l++;
			}
		if (l > m) cout << "Error!" << endl;
		}
	}
	Graph G(n, m, E);
	PrQueue<Edge>* Q = new PrQueueBasedDHeap<Edge>(m);
    Edge* WE = new Edge[n - 1];
	AlgoritmKraskala AK;
	WE = AK.Kraskal(&G, Q);
	for (int i = 0;i < n-1;i++)
	{
		cout << "(" << WE[i].GetStart() << ","; 
		cout<< WE[i].GetFinish() << ")" << ",";
	}

	return 0;
}