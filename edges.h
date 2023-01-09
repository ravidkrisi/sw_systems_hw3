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
    node *start;
    node *end;
    edge *next_edge;
} edge;

void add_edge(graph *graph_p, node *start, node *end, int weight)
{
    edge *edge_p = malloc(sizeof(edge));
    if(edge_p == NULL)
    {
        printf("not enough space to create edge");
        exit(1);
    }
    edge_p->start = start;
    edge_p->end = end;
    edge_p->weight = weight;
    edge_p->next_edge = start->edges_list_head; 
    start->edges_list_head = edge_p;
    //start->edges_list_head: (1,5)->(1,3)->(1,2)
    //edge_p:(1,1)
    //edge_p->next_edge = start->edges_list_head: (1,1)->(1,5)->(1,3)->(1,2)
    //start->edges_list_head = edge_p: (1,1)->(1,5)->(1,3)->(1,2)
}