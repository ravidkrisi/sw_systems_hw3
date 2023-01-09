#pragma once
#include <stdio.h>
#include "algo.h"
#include "edges.h"
/**
 * struct that holds the node object 
*/
typedef struct node 
{
    int data; 
    edge *edges_list_head;
    node *next_node;
} node;

//decleretions of all the methods

void add_node(graph *graph_p, int data);

node* get_node(graph *graph_p, int data);
