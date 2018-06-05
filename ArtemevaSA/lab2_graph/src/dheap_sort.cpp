#include "dheap_sort.h"
#include "dheap.h"
//#include "graph.h"
void PiramidSortBasedDHeap::PiramidSort(int* keys, int n) 
{
	DHeap<int> heap(keys,n);
	heap.Heap();
	while (heap.GetCurrSize() > 1)
	{
		heap.Transp(0, heap.GetCurrSize() - 1);
		heap.ChangeCurrSize(heap.GetCurrSize()-1);
		heap.Sink(0);
	}
	heap.Print();
}