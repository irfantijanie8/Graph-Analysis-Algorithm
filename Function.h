#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>  
using namespace std;

#define INF 9999999

const int ver =5;
const int CompleteGraph[ver][ver]={
{   0, 7130, 6551, 8429, 7800},
{7130,    0, 1216,12417, 9643},
{6551, 1216,    0,12985,10402},
{8429,12417,12985,    0, 2926},
{7800, 9643,10402, 2926,    0}
};

const int DefaultGraph[ver][ver]={
	{0,7130,   0,   0,7800},
	{0,   0,1216,   0,   0},
	{0,   0,   0,12985,   0},
	{0,   0,   0,   0,   0},
	{0,   0,   0,2926,   0}
	};

const string cities[5] = {"Boston","Tirana","Warsaw","Santiago","Rio"};

void printGraph(int graph[][ver])
{
	for(int i=0; i<ver; i++)
	{
		for(int j=0; j<ver; j++)
			cout << graph[i][j] << "\t";
		cout<<"\n";
	}
}

void deleteEdge(int graph[][ver], int start, int end)
{
	if(start<ver&&end<ver)
		graph[start][end]=0;
}

void removeEdge(int graph[][ver])
{
	do{
		system ("CLS");
		cout << "Select edges to be removed\n\n";
		cout << "Cities:-\n\n";
		for(int i=0; i<ver; i++)
		{
			cout << cities[i] << " - " << i << endl;
		}
		cout << endl;
		printGraph(graph);
		
		int startCities = -1, endCities = -1;
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
			if(graph[startCities][endCities]==0)
			{
				cout << "\nEdges don't exist\n";
				continue;
			}
			deleteEdge(graph, startCities, endCities);
			cout << "Edge " << cities[startCities] << " -> " << cities[endCities] << " removed\n\n";
			break;
	}
	while(1);
}

void addEdge(int graph[][ver], int start, int end)
{
	graph[start][end] = CompleteGraph[start][end];
}

void Reset(int graph[][ver])
{
	copy(&DefaultGraph[0][0], &DefaultGraph[0][0]+ver*ver,&graph[0][0]);
}

void addRandomEdge(int graph[][ver])
{
	int randStart = rand() %ver;
	int randEnd = rand() %ver;
	
	if(graph[randStart][randEnd]==0&&randStart!=randEnd)
	{
		addEdge(graph, randStart, randEnd);
	}
		
	else
		addRandomEdge(graph);	
}

#endif
