#ifndef ShortestPath_H
#define ShortestPath_H

#include <iostream>
using namespace std;
#include <limits.h>
#include <cstdlib>
#include <time.h>
#include <queue>
#include "Function.h"

void insert(int graph[ver][ver]);

// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < ver; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
 
// A utility function to print the constructed distance array
void printSolution(int dist[], int start, int end)
{
    //cout <<"The shortest path distance from node " << start << " to node "<< end << endl;
    
    for (int i = end; i < ver; i++)
{
	//        cout  << i << " \t\t"<<dist[i]<< endl;
	if(dist[end]!=INT_MAX)
    cout << "\nThe shortest distance from node " << start << " to node " << i << " is:" << dist[i] << endl;
	break;	
}

}


 
// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[ver][ver], int start, int end)
{
    int dist[ver]; // The output array.  dist[i] will hold the shortest distance from source to i
 
    bool sptSet[ver]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < ver; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[start] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < ver-1 ; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < ver; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v];
				
			
                
    }
 
    // print the constructed distance array
    printSolution(dist,start,end);
    if(dist[end] == INT_MAX)
    {
    	addRandomEdge(graph);
    	dijkstra(graph,start,end);
	}
}
 
 
 void insert(int graph[ver][ver]) {
 	 int start;
     int end;
     
    cout << endl;
 	cout << "Please insert the start node : " << endl;
	cin >> start;
	cout << "Please insert the end node :" << endl;
	cin >> end;
		
    dijkstra(graph,start,end);
 	
 }
 
 #endif
 

