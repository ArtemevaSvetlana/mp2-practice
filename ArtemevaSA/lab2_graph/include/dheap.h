#pragma once

#include "graph.h"
//#include "pr_queue.h"
#include <iostream>

using namespace std;

template <typename T>
class DHeap
{
	static const int d = 2;			// d-куча
	T* keys;						// массив ключей
	int n;							// максимальное число ключей
	int k;							// текущее число ключей 
public:

	DHeap() {};
	DHeap(int MaxSize);
	DHeap(T* edges, int size);
	//DHeap(Graph graph);
	~DHeap();

	void Transp(int i, int j);
	void Emerge(int i); //всплытие
	void Sink(int i); //погружение
	int Minchild(int id);
	T DelMinKey();
	void Insert(const T& key);
	void Heap(); //окучивание

	int GetMaxSize() { return n; };
	int GetCurrSize() { return k; };
	void ChangeCurrSize(int curr) { k = curr; };

	void Print();
};

//=================================================

template <typename T>
DHeap<T>::DHeap(T* edges, int size)
{
	n = size;
	keys = new T[n];
	for (int i = 0;i < n;i++)
	{
		keys[i] = edges[i];
	}
	k = n;
};

//=================================================

template <typename T>
DHeap<T>::~DHeap()
{
	delete[] keys;
}

//=================================================

template <typename T>
DHeap<T>::DHeap(int MaxSize)
{
	n = MaxSize;
	k = 0;
	keys = new T[n];
};

//=================================================

template <typename T>
void DHeap<T>::Transp(int i, int j)
{
	T t = keys[i];
	keys[i] = keys[j];
	keys[j] = t;
}


//=================================================

template<typename T>
void DHeap<T>::Insert(const T& key)
{
	if (k >= n) throw("Error insert");
	
	keys[k] = key;
	Emerge(k);
	k++;
}

//================================================

template<typename T>
void DHeap<T>::Emerge(int i)
{
	int p;
	while (i>0)
	{
		p = (i - 1) / d;
		if (keys[p] > keys[i])
		{
			Transp(i, p);
			i = p;
		}
		else break;
	}
}

//================================================

template<typename T>
void DHeap<T>::Sink(int i)
{
	int c = Minchild(i);
	while (c != -1 && keys[c] < keys[i])
	{
		Transp(c, i);
		i = c;
		c =Minchild(i);
	}

}

//================================================

template<typename T>
int DHeap<T>::Minchild(int id)
{
	if (id + 1 > k) return -1;

	if (id + 1 == k) return id;
	else
	{
		int firstchild = id + 1;
		int lastchild = min(id+k,k);
		T minkey = keys[firstchild];
		int minch = firstchild;
		for (int i = firstchild; i < lastchild; i++)
		{
			if (keys[i] < minkey)
			{
				minkey = keys[i];
				minch = i;
			}
		}
		return minch;

	}
}

//================================================

template<typename T>
T DHeap<T>::DelMinKey()
{
	T tmp = keys[0];
	keys[0] = keys[k - 1];
	k--;
	Sink(0);
	return tmp;
}

//================================================

template<typename T>
void DHeap<T>::Heap()
{
	for (int i = (n - 1); i >= 0; i--)
	{
		Sink(i);
	}
}

//================================================

template<typename T>
void DHeap<T>::Print()
{
	for (int i = 0;i < n;i++)
	{
		cout << keys[i]<<" ";
	}
}

