#include "algo.h"

/**
 * @param nodes_number the number of nodes in the graph
 * this method creates a graph with the number of nodes 
 * @return pointer to the graph we created 
*/
graph* create_graph(int nodes_number)
{
    graph *graph_p = malloc(sizeof(graph));
    if(graph_p == NULL)
    {
        printf("not enough space to create graph");
        exit(1);
    }
    graph_p->head_node = NULL;
    graph_p->nodes_number =nodes_number;
    return graph_p;
}

/**
 * @param graph_p pointer to the graph
 * @param data holds the number of the node
 * this method returns 1 if the node is in the graph,
 * else return 0
*/
int is_node_in_graph(graph *graph_p, int data)
{
    node *temp = graph_p->head_node;
    while(temp!=NULL)
    {
        if(temp->data == data)
        {
            return 1;
        }
        temp = temp->next_node;
    }
    return 0;
}

