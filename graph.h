#include <stdio.h>
#include <stdlib.h>

#define INF 999999


/**
 * struct that holds the edge object 
*/
typedef struct edge edge;
struct edge
{
    int weight; 
    int start;
    int  end;
    edge *next_edge;
};

/**
 * struct that holds the node object 
*/
typedef struct node node;
struct node 
{
    int data; 
    int distance;
    int visited;
    edge *edges_list_head;
    node *next_node;
};

/**
 * struct that holds the graph object 
*/
typedef struct graph graph;
struct graph{
    node *head_node;
    int nodes_number;
};


/**
 * decleretions for the methods in the c file 
*/
graph* create_graph(int nodes_number);

void free_graph(graph *graph_p);

int is_node_in_graph(graph *graph_p, int data);

int dijkstra(int start, int end, graph *gh);

void tsp( int *arr, int start, int end, graph *graph_p, int *cost);

void print_graph(graph *gh);

void free_outward_edges(node *node_p);

void add_edge(node *start_p, int start, int end, int weight);

void free_edge(edge *edge_p);

void free_edges_going_to_node(graph *graph_p, int end);

void add_node(graph *graph_p, int data);


node* get_node(graph *graph_p, int data);

void free_node(int data, graph *graph_p);