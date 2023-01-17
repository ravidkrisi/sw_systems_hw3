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
 * @param data the index of the node
 * @param gr pointer to the graph
*/
void free_node(int data, graph *gr)
{
    node *node_p = get_node(gr, data);
    if(node_p!=NULL)
    {
    free_outward_edges(node_p);


    node *head = gr->head_node;
    node *temp = NULL;
    if(head !=NULL)
    {
    if( head->data == data)
    {
        gr->head_node =head->next_node;
        free(head);
        return;
    }
    else
    {
        temp = head->next_node;
        while(temp!=NULL)
        {
            if(temp->data == data)
            {
                head->next_node = temp->next_node;
                free(temp);
                return;
            }
            head = temp;
            temp = temp->next_node;
        }

    }
    }
}
}
