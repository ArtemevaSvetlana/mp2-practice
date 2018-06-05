#pragma once
#include "pr_queue.h"
#include "dheap.h"
#include "graph.h"


template <typename T>
class PrQueueBasedDHeap: public PrQueue<T>
{
public:
	DHeap<T>* H;
	PrQueueBasedDHeap(int n);
	~PrQueueBasedDHeap() {};

	void Push(T val);
	 T Pop();
	 bool IsEmpty();
};


template <typename T>
PrQueueBasedDHeap<T>::PrQueueBasedDHeap(int n)
{
	H = new DHeap<T>(n);
}


template <typename T>
void PrQueueBasedDHeap<T>::Push(T val)
{
	H->Insert(val);
}

template <typename T>
T PrQueueBasedDHeap<T>::Pop()
{
	T t = H->DelMinKey();
	return t;
}


template <typename T>
bool PrQueueBasedDHeap<T>::IsEmpty()
{
	if ( H->GetCurrSize() == 0 )
		return true;
	else
		return false;
}
