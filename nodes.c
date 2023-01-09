#include "nodes.h"

/**
 * @param graph_p = pointer to the graph
 * @param data = var hold the number of the node
 * this method adds the node to the graph
*/

void add_node(graph *graph_p, int data)
{
    node *node_p = malloc(sizeof(node));
    if(node_p == NULL)
    {
        printf("not enough space to create node");
        exit(1);
    }
    node_p->data = data;
    node_p->edges_list_head = NULL;
    node_p->next_node = graph_p->head_node;
    graph_p->head_node = node_p;
}

/**
 * @param graph_p pointer to the graph 
 * @param data holds the node data
 * the method looking for the instance of the node's data in
 * the graph and returns it 
*/
node* get_node(graph *graph_p, int data)
{
    node *temp = graph_p->head_node;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            return temp;
        }
    }
}