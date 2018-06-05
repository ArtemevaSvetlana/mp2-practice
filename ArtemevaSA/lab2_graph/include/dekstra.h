#pragma once
#include "graph.h"
#include "pr_queue.h"

class AlgoritmDekstri
{
public:
	void Dekstra(Graph* g, PrQueue<Vertex>* q);
};