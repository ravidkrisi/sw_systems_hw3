#include "graph.h"

int main()
{
    //intialize vars 
    char char_input ='Z';
    int int_input =0, node_start=0, node_end=0, weight=0;
    node *node_start_p, *node_end_p;

    graph *graph_p=NULL;
    while(scanf(" %c", &char_input)!=EOF)
    {
        if(char_input == 'A')
        {
            /**
             * check weather a graph was already created by the user,
             * if so delete and create a new one 
             */
            if(graph_p == NULL)
            {
                scanf(" %d", &int_input);
                graph_p = create_graph(int_input);
            }
            else
            {
                free_graph(graph_p);
                scanf(" %d", &int_input);
                graph_p = create_graph(int_input);                
            }
        }  

        else if(char_input == 'n')
        {

            //check if the node exist in the graph, else add it 
            scanf(" %d", &node_start);
            if(is_node_in_graph(graph_p, node_start) == 0)
            {
            add_node(graph_p, node_start);
            }
            //enter the node pointer to node_start_p
            node_start_p = get_node(graph_p, node_start);
            
            //scanning all the edges out of the node
            while(1)
            {
                int flag=scanf(" %d", &node_end);
                if(flag!=1)
                {
                    break;
                }
                scanf(" %d", &weight);
                //check if the node exist in the graph, else add it
                if(is_node_in_graph(graph_p, node_end) == 0)
                {
                add_node(graph_p, node_end);
                }
                //enter the node pointer to node_end_p
                node_end_p = get_node(graph_p, node_end);
                //add the edge to the graph
                add_edge(node_start_p, node_start, node_end, weight);
            }
            
        } 
        else if(char_input == 'B')
        {
            scanf(" %d", &node_start);
            //if node is not in the graph add it 
            if(is_node_in_graph(graph_p, node_start)==0)
            {
                add_node(graph_p, node_start);
                node_start_p = get_node(graph_p, node_start);
            }
            //else delete all outward edges of the node
            else
            {
                node_start_p = get_node(graph_p, node_start);
                free_outward_edges(node_start_p);
            }
            //scanning all edges out of the node
            while(1)
            {
                int flag=scanf(" %d", &node_end);
                if(flag!=1)
                {
                    break;
                }
                scanf(" %d", &weight);

                node_end_p = get_node(graph_p, node_end);
                //add the edge to the graph
                add_edge(node_start_p, node_start, node_end, weight);
            }
        }
        else if(char_input == 'D')
        {
            scanf(" %d", &int_input);
            node *head_p= graph_p->head_node;
            free_edges_going_to_node(head_p, int_input);
            node_start_p = get_node(graph_p, int_input);
            free_node(node_start_p, graph_p);
        }

        else if(char_input == 'S')
        {
            scanf(" %d", &node_start);
            scanf(" %d", &node_end);
            int dist = dijkstra(node_start, node_end, graph_p);
            printf("Dijsktra shortest path: %d \n", dist);
        }

        else if(char_input == 'T')
        {
            scanf(" %d", &int_input);
            int arr [int_input];
            for(int i = 0; i<int_input; i++)
            {
                scanf( "%d", &arr[i]);
            }
            int *cost_p = malloc(sizeof(int));
            *cost_p = INF;
            tsp(arr, 0, int_input-1, graph_p, cost_p);
            if(*cost_p == INF) *cost_p =-1;
            printf("TSP shortest path: %d \n", *cost_p);
            free(cost_p);
        }

    }
    return 0;
}