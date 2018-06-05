#pragma once
//#include <iostream>
#include "graph.h"
#include "dekstra.h"
#include "pr_queue.h"
#include "pr_queue_based_dheap.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n,m;
	cout << "������� ����� ������ ������ �����" << endl;
	cin >> n;
	cout << "������� ����� ����� ������ �����" << endl;
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

	PrQueue<Vertex>* Q = new PrQueueBasedDHeap<Vertex>(m);
	AlgoritmDekstri AD;
	AD.Dekstra(&G, Q);

	return 0;
}