#include "graph.h"

/**
 * this method adds the node to the graph
 * @param graph_p = pointer to the graph
 * @param data = var hold the number of the node
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
 * the method looking for the instance of the node's data in
 * @param graph_p pointer to the graph 
 * @param data holds the node data
 * @return node pointer to the node 
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
        temp= temp->next_node;
    }
}

/**
 * this method free the node and the linked list of edges going outward
 * @param node_p pointer to the node
 * @param gr pointer to the graph
*/
void free_node(node *node_p, graph *gr)
{
    free_outward_edges(node_p);

    node *head = gr->head_node;
    node *temp = node_p->next_node;

    //if node_p is the head of the list 
    if (head->data == node_p->data)
    {
        gr->head_node = temp;
        free(node_p);
    }

    //if node_p is not the head list
    while(head != NULL)
    {
        if(head->next_node->data == node_p->data)
        {
            head->next_node = temp;
            free(node_p);
        }
        head=head->next_node;
    }
}
