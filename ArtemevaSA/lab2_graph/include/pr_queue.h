#pragma once
#include "dheap.h"
#include "graph.h"
#include "dekstra.h"
template <typename T>
class PrQueue
{
public:
	PrQueue() {};
	PrQueue(int Maxsize);

	virtual void Push(T val) {};
    virtual T Pop();
	virtual bool IsEmpty();
};

//================================

template <typename T>
T PrQueue<T>::Pop()
{
	T t;
	return t;
}

//================================

template <typename T>
bool PrQueue<T>::IsEmpty()
{
	return true;
}