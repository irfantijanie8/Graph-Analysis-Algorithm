#ifndef MST_H
#define MST_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <queue>
#include "Function.h"
using namespace std;

int parent[ver];

int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void merge(int i, int j)
{
	int a = find(i);
	int b = find(j);
	//cout << "Parent - " << a << "-> " << parent[a] << " - ";
	parent[a] = b;
	//cout << parent[a] << endl;
}

void MST(int graphStart[][ver])
{
	
	int graph[ver][ver]={0};
	int mincost = 0;
	
	char choiceEdges = 'n';
	do{
		cout << "\nDo you want to select more edges (y-yes, n-no): ";
		cin >> choiceEdges;
		choiceEdges = tolower(choiceEdges);
		system("CLS");
		if(choiceEdges!='y'&&choiceEdges!='n')
		{
			cout << "Invalid input\n\n";
			continue;
		}
	
		if(choiceEdges=='n')
			break;

		cout << "select edges\n\n";
		cout << "Cities:-\n\n";
		for(int i=0; i<ver; i++)
		{
			cout << cities[i] << " - " << i << endl;
		}
		printGraph(graphStart);
		
		int startCities = -1, endCities = -1;

		if(choiceEdges=='y')
		{
			cout << "\nEnter starting cities in number: ";
			cin >> startCities;
			if(cin.fail()||startCities<0||startCities>=ver)
			{
				cout << "Invalid input\n\n";
				continue;
			}
		
			cout << "Enter ending cities in number: ";
			cin >> endCities;
			if(cin.fail()||endCities<0||endCities>=ver)
			{
				cout << "Invalid input\n\n";
				continue;
			}
			if(graphStart[startCities][endCities]==0)
			{
				cout << "Edges don't exist\n\n";
				continue;
			}
			graph[startCities][endCities] = graphStart[startCities][endCities];
		}
	
	}
	while(choiceEdges=='y');
	
	
	
	
	bool noTree=false;
	do{
		
		int min;
		int edge_count = 0;	
		for (int i = 0; i < ver; i++)
		parent[i] = i;
		
		while (edge_count < ver-1) {
			for(int i=0; i<ver; i++)
			{
				for(int j=0; j<ver; j++)
				{
					if(graph[i][j]==0)
					graph[i][j]=INF;
				}
			}
		
			min = INF;
			int a = -1, b = -1;
			for (int i = 0; i < ver; i++) {
			
				for (int j = 0; j < ver; j++) {
					if (find(i) != find(j) && graph[i][j] < min) {
						min = graph[i][j];
						//cout << parent[i] << " - " << parent[j] << endl;
						a = i;
						b = j;
					}
				}
			
			}
		
			if(min==INF)
			{
				for(int i=0; i<ver; i++)
				{
					for(int j=0; j<ver; j++)
					{
						if(graph[i][j]==INF)
						graph[i][j]=0;
					}
				}
				addRandomEdge(graph);
				break;
			}
		
			//for(int i=0; i<ver; i++)
				//cout << parent[i] << ", ";
			//cout << endl;
			merge(a, b);
			cout << "Edge " << edge_count++ << ": (" << cities[a] << " -> " << cities[b] << ") cost: " << min << endl;
			mincost += min;
		}
	
		if(min!=INF)
		{
			//for(int i=0; i<ver; i++)
				//cout << parent[i] << ", ";
			cout << "\nMinimum cost= " << mincost << "\n\n";
			system("pause");
			system("cls");
			noTree = false;
		}
		else
		{
			cout << "No Tree in the graph. Adding random edges\n\n"; 
			noTree = true;
		}
	}
	while(noTree);
		
	
}

#endif
