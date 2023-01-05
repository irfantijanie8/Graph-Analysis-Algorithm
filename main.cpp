#include <iostream>
#include <cstdlib>
#include <time.h>  
#include "Function.h"
#include "MST.h"
#include "StrongConnectivity.h"
#include "CycleDetection.h"
#include "ShortestPath.h"

using namespace std;

int main()
{ 
	const string acronyms[ver] = {"BO", "TI", "WA", "SA", "RI"};
	srand (time(NULL));
	int Graph[ver][ver];
	Reset(Graph);

    bool exit = false;
    string choice;
	
	while(!exit) {
		cout << "-----------Cities-------------" << endl << endl;
		for(int i=0; i<ver; i++)
		{
			cout << "City " << i << " : "<< cities[i] << " - " << acronyms[i] << endl;
		}
		cout << endl;
		cout << "-----------Graph ------------\n";

		for (int i = 0; i < ver; ++i) 
		{
    	cout << acronyms[i] << "\t";
    	}
    	cout << "\n";
    	printGraph(Graph);
		//graph.printGraph();
		cout << endl;
		cout << "----------Main Program-----------" << endl;
		cout << "[1] Strong Connectivity" << endl;
		cout << "[2] Cycle Detection" << endl;
		cout << "[3] Shortest Path" << endl;
		cout << "[4] Minimum Spanning Tree" << endl;
		cout << "[5] Reset Graph" << endl;
		cout << "[6] manual edge remover" << endl;
		cout << "[0] exit" << endl;
		
		cout << "Enter your choice :";
		cin >> choice;
		
		system("cls");
		cin.ignore();
			
		if(!choice.empty() && isdigit(choice[0])) {
			switch((int) choice[0] - (int) '0'){
				case 1:
					cout << "-----------Strong Connectivity ------------\n\n";
					cout << "*****************************************\n"
	     				 << "                  Graph                  \n"
	     				 << "*****************************************\n";
					for (int i = 0; i < ver; ++i) 
						{
    						cout << acronyms[i] << "\t";
    					}
    					cout << "\n";
    					printGraph(Graph);
    					cout << "\n";
   
					//Check strong connectivity of the graph
					if(isStronglyConnected(Graph))
   					{
   						cout << "The graph is strongly connected.\n";	
   					}
   					else
   					{
   						cout << "The graph is not strongly connected.\n";
   						//If the graph is not strongly connected, add random edge until 
						//the strongly connected graph is found
   						do
						{
							addRandomEdge(Graph);
						}
						while(!isStronglyConnected(Graph));
					
						cout << "\n\n";
				    	cout << "****************************************************\n"
	     				     << "       The graph after adding random edge       \n"
	     				     << "****************************************************\n";
						for (int i = 0; i < ver; ++i) 
						{
				    		cout << acronyms[i] << "\t";
				    	}
				    	cout << "\n";
						printGraph(Graph);
						cout << "\n";
						cout << "The graph is now strongly connected!\n";
   					}

					system("pause");
					system("cls");
					break;
				case 2:
					cout << "-----------Cycle Detection ------------\n\n";
					cout << "*****************************************\n"
	     				 << "                  Graph                  \n"
	     				 << "*****************************************\n";
					for (int i = 0; i < ver; ++i) 
						{
    						cout << acronyms[i] << "\t";
    					}
    					cout << "\n";
    					printGraph(Graph);
    					cout << "\n";
   
					//detecting cycle
					if(hasCycle(Graph))
   					{
   						cout << "The graph has cycle.\n";	
   					}
   					else
   					{
   						cout << "The graph has no cycle.\n Adding random edge ..";
   						//If the graph has no cycle, add random edge until 
						//the cycle is found
   						do
						{
							addRandomEdge(Graph);
							system("pause");
						}
						while(!hasCycle(Graph));
					
						cout << "\n\n";
				    	cout << "****************************************************\n"
	     				     << "       The graph after adding random edge       \n"
	     				     << "****************************************************\n";
						for (int i = 0; i < ver; ++i) 
						{
				    		cout << acronyms[i] << "\t";
				    	}
				    	cout << "\n";
						printGraph(Graph);
						cout << "\n";
						cout << "The graph has cycle!\n";
   					}

					system("pause");
					system("cls");

					break;
				case 3:
					cout << "-----------Shortest Path ------------\n\n";
					cout << "*****************************************\n"
	     				 << "                  Graph                  \n"
	     				 << "*****************************************\n";
					for (int i = 0; i < ver; ++i) 
						{
    						cout << acronyms[i] << "\t";
    					}
    					cout << "\n";
    					printGraph(Graph);
    					cout << "\n";
    					
					while(true) {
					insert(Graph);
					system("pause");
					system("cls");
					break;
 					}
					break;
				case 4:
					MST(Graph);
					break;
				case 5:
					Reset(Graph);
					break;
				case 6:
					removeEdge(Graph);
					system("pause");
					system("cls");
					break;	
				case 0:
					return 0;
				default:
					cout << " Invalid choice. "<< endl;
					break;
			}
			} else {
				cout << "Invalid input detected" << endl << endl;
			}
		}
		cout << "Thanks for using'	";


	//srand (time(NULL));
	//int Graph[ver][ver];
	//Reset(Graph);
	
	//addRandomEdge(Graph);
	//printGraph(Graph);
	
	return 0;
	
}
	

