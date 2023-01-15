#pragma once
#include "algo.h"
#include "nodes.h"
#include <stdio.h>

/**
 * struct that holds the edge object 
*/
typedef struct edge
{
    int weight; 
    int start;
    int  end;
    edge *next_edge;
} edge;


//decleretions of methods
void free_outward_edges(node *node_p);

void add_edge(node *start_p, int start, int end, int weight);
