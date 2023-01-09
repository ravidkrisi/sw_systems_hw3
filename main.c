#pragma once
#include "edges.h"
#include "nodes.h"
#include "algo.h"
#include <stdio.h>

int main()
{
    //intialize vars 
    char char_input ='T';
    int int_input =0, node_start=0, node_end=0, weight=0;
    node *node_start_p, *node_end_p;

    graph *graph_p=NULL;
    while(scanf("%c", char_input)!=EOF)
    {
        if(char_input == 'A')
        {
            /**
             * check weather a graph was already created by the user,
             * if so delete and create a new one 
             */
            if(graph_p == NULL)
            {
                scanf("%d", &int_input);
                graph_p = create_graph(int_input);
            }

            while(scanf("%c", &char_input) == 'n')
            {
                //check if the node exist in the graph, else add it 
                scanf("%d", &node_start);
                if(is_node_in_graph(graph_p, node_start) == 0)
                {
                add_node(graph_p, node_start);
                }
                //enter the node pointer to node_start_p
                node_start_p = get_node(graph_p, node_start);

                while(scanf("%c", &char_input) != 'n')
                {
                    scanf("%d", &node_end);
                    scanf("%d", &weight);
                    //check if the node exist in the graph, else add it
                    if(is_node_in_graph(graph_p, node_end) == 0)
                    {
                    add_node(graph_p, node_end);
                    }
                    //enter the node pointer to node_end_p
                    node_end_p = get_node(graph_p, node_end);

                    //add the edge to the graph
                    add_edge(graph_p, node_start_p, node_end_p, weight);
                }
            }
        }
        
    }
    return 0;
}