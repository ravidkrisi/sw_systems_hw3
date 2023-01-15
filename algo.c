#include "graph.h"

/**
 * this method creates a graph with the number of nodes
 * @param nodes_number the number of nodes in the graph 
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
 * this method returns 1 if the node is in the graph
 * @param graph_p pointer to the graph
 * @param data holds the number of the node
 * @return 1 if the node is in the graph, else return 0
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
/**
 * this method find the shortest path between start and end using dijkstra algo
 * @param start index of the start node 
 * @param end index of the end node 
 * @param gh pointer to the graph 
 * @return the shortest path between start and end nodes
*/
int dijkstra(int start, int end, graph *gh)
{
    node *start_p = get_node(gh, start);
    node *end_p = get_node(gh, end);
    node *head = gh->head_node;
    int min = INF;
    int min_index = start;

    //set all node's distance to INF
    while(head!=NULL)
    {
        head->distance = INF;
        head->visited = 0;
        head = head->next_node;
    }
    //set start node's distance to 0
    start_p->distance = 0;


    while(start_p->visited!=1)
    {
    edge *edge_head = start_p->edges_list_head;

    //updating the distance from start node to all edges end node
    while(edge_head!=NULL)
    {
        //set pointer to the node in the end of the edge
        end_p=get_node(gh, edge_head->end);
        //examine only the nodes we have not visited 
        if(end_p->visited == 0)
        {
        if(start_p->distance+edge_head->weight<end_p->distance)
        {
            end_p->distance=start_p->distance+edge_head->weight;
            if(end_p->distance<min)
            {
                min = end_p->distance;
                min_index = end_p->data;
            }
        }
        }
        edge_head = edge_head->next_edge;
    }
    //finish itereting all the edges of the node and going to the shortest path node
    start_p->visited = 1;
    start_p = get_node(gh, min_index);
    }

    //set pointer to the end node we supposed to check the distance and return the distance
    end_p = get_node(gh, end);
    return end_p->distance;
}

void print_graph(graph *gh)
{
  node *node_p = gh->head_node;
  edge *edge_p = NULL;

  while(node_p!=NULL)
  {
    printf("node: %d\n", node_p->data);
    edge_p = node_p->edges_list_head;
    while(edge_p!=NULL)
    {
        printf("edge:(%d,%d)\n", edge_p->start, edge_p->end);
        edge_p = edge_p->next_edge;
    }
    node_p=node_p->next_node;
  }
}
/**
 * this method free all the graph nodes
 * @param graph_p pointer to the graph 
*/
void free_graph(graph *graph_p)
{
    node *head = graph_p->head_node;
    node *temp = NULL;
    while(head != NULL)
    {
        temp = head->next_node;
        free_node(head, graph_p);
        head = temp;
    }
}

