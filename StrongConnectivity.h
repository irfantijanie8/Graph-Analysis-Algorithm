#ifndef StrongConnectivity_H
#define StrongConnectivity_H
#include <iostream>
#include <cstdlib>
#include<vector>
#include<stack>
#include <bits/stdc++.h>
#include<stdlib.h>
#include <time.h>  
#include "Function.h"
using namespace std;

 
//DFS algorithm
void dfs(int g[ver][ver], int u, bool visited[]) 
{
   visited[u] = true;    //mark v as visited

   for(int v = 0; v<ver; v++) {
      if(g[u][v]) {
         if(!visited[v])
            dfs(g, v, visited);
      }
   }
}  

//Transpose the graph and store to transGraph
void transpose(int graph[][ver]) 
{  
	int transGraph [ver][ver]; 
   	for(int i = 0; i<ver; i++)
      for(int j = 0; j<ver; j++)
         transGraph[i][j] = graph[j][i];
} 

//Check the graph whether strongly connected or not
bool isStronglyConnected(int graph[][ver]) 
{
   bool *vis = new bool[ver];
   
   //for all vertex u as start point, check whether all nodes are visible or not
   for(int u; u < ver; u++) 
   {
      	for(int i = 0; i<ver; i++)
         vis[i] = false;    //initialize as no node is visited
         
       	dfs(graph, u, vis);
         
        for(int i = 0; i<ver; i++) 
		{
            if(!vis[i])         //if there is a node, not visited by traversal, graph is not connected
               return false;
         }
         
         transpose(graph);    //make reversed graph
         
         for(int i = 0; i<ver; i++)
         vis[i] = false;    //initialize as no node is visited
         
         dfs(graph, u, vis);
         
         for(int i = 0; i<ver; i++) 
		 {
            if(!vis[i])         //if there is a node, not visited by traversal, graph is not connected
               return false;
         }
   }
   return true;
}

#endif
