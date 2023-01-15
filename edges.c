#pragma once
#include <stdio.h>
#include "algo.h"
#include "nodes.h"


/**
 * this method add an edge to the edge list of the node
 * @param  start_p pointer to the node the edge coming out of 
 * @param start the index of the node the edge is coming out 
 * @param end the index of the node the edge is going in 
 * @param weight the weight of the edge 
*/
void add_edge(node *start_p, int start, int end, int weight)
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
    edge_p->next_edge = start_p->edges_list_head; 
    start_p->edges_list_head = edge_p;
    //start->edges_list_head: (1,5)->(1,3)->(1,2)
    //edge_p:(1,1)
    //edge_p->next_edge = start->edges_list_head: (1,1)->(1,5)->(1,3)->(1,2)
    //start->edges_list_head = edge_p: (1,1)->(1,5)->(1,3)->(1,2)
}

/**
 * this method get a pointer to a node and free all the outward edges of the node
 * @param node_p pointer to the node
*/
void free_outward_edges(node *node_p)
{
    edge *head = node_p->edges_list_head;
    edge *temp = NULL;
    while(head!=NULL)
    {
    temp = head->next_edge;
    free(head);
    head=temp;
    }
}

/**
 * this method free all the edges with matched end index to the node we want to delete
 * @param head pointer to the nodes head list of the graph
 * @param end the index of the node we want to delete
*/
void edges_going_to_node(node *head, int end)
{
    while(head!=NULL)
    {
    edge *edge_head = head->edges_list_head;
    edge *temp = NULL;
    //if the edge is connected to the end node and the head of the edges list
    if(edge_head->end==end)
    {
        head->edges_list_head=edge_head->next_edge;
        free(edge_head);
    }
    //looping over all the edges list to delelte edges with matched end index
    while(edge_head!=NULL)
    {
       temp = edge_head->next_edge;
       if(temp->end == end)
       {
        edge_head->next_edge = temp->next_edge;
        free(temp);
       }
       edge_head=edge_head->next_edge;
    }
    head=head->next_node;
    }
}