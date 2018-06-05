#pragma once
#include "graph.h"
#include "pr_queue_based_dheap.h"

class AlgoritmKraskala
{
public:
	Edge* Kraskal(Graph*g,PrQueue<Edge>* q);
};