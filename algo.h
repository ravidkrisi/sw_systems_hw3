#pragma once
#include "edges.h"
#include "nodes.h"
#include <stdio.h>

#define INF 999999
/**
 * struct that holds the graph object 
*/
typedef struct graph{
    node *head_node;
    int nodes_number;
} graph;

/**
 * decleretions for the methods in the c file 
*/
graph* create_graph(int nodes_number);

int is_node_in_graph(graph *graph_p, int data);

int dijkstra(int start, int end, graph *gh);

void print_graph(graph *gh);