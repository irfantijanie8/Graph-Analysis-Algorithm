#ifndef CycleDetection_H
#define CycleDetection_H

#include <iostream>
#include <cstdlib>
#include<set>
#include<stdlib.h>
#include <time.h>  
#include "Function.h"
//#include "StrongConnectivity.h"

//white  - unvisited
//grey - currently visiting 
//black - visted complete

bool cycleDfs(int curr, set<int>&wSet, set<int>&gSet, set<int>&bSet, int g[][ver]) {
   //moving currently visiting vertex
   //from white set to grey set.
   wSet.erase(wSet.find(curr));
   gSet.insert(curr);

   for(int v = 0; v < ver; v++) {
      if(g[curr][v] != 0) {    //for all adjacent vertices
         if(bSet.find(v) != bSet.end())
            continue;    //if the vertices found are in the black set
         if(gSet.find(v) != gSet.end())
            return true;    //it is a cycle if adjacent verticex found in grey set
         if(cycleDfs(v, wSet, gSet, bSet,g)) //recursive dfs 
            return true;    //cycle found
      }
   }

   //moving v to grey set to black set.
   gSet.erase(gSet.find(curr));
   bSet.insert(curr);
   return false;
}

bool hasCycle(int g[][ver]) {
   set<int> wSet, gSet, bSet;    //three set as white, grey and black
   for(int i = 0; i<ver; i++)
      wSet.insert(i);    //all unvisited vertex will be put in white set

   while(wSet.size() > 0) {
   	//do for all verteices in white set
      for(int current = 0; current < ver; current++) {
         if(wSet.find(current) != wSet.end())
            if(cycleDfs(current, wSet, gSet, bSet,g)) //call function to detect cycle
               return true;
      }
   }
   return false;
}

#endif
