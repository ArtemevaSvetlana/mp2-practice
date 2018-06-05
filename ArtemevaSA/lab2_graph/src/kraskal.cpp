#include "kraskal.h"
#include "separated_sets.h"

Edge* AlgoritmKraskala::Kraskal(Graph*g, PrQueue<Edge>* queue)
{
	SeparatedSets U(g->GetN());
	int nE = g->GetN() - 1; //����� ����� � ������� ������������ ��������� ������
	int kE = 0; // ����� ����� � �������� ������ ������
	Edge* E = new Edge[nE];
	for (int i = 0;i < g->GetM();i++)
	{
		queue->Push(g->GetEdge(i));
	}
	while ((!queue->IsEmpty()) &&(kE < nE))
	{
		Edge Tmp = queue->Pop();
		int A = Tmp.GetStart(), B = Tmp.GetFinish();
		if (U.DefineSubset(A) != U.DefineSubset(B)) 
		{
			U.Unite(B, A);
			E[kE] = Tmp;
			kE++;
		}
	}

	return E;
}