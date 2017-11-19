#include <stdio.h>
#include <stdlib.h>
#include "ALbaseGraph.h"

void graphInit(ALGraph *pg, int nv){
  int i;
  pg->adjList = (List*)malloc(sizeof(List)*nv);
  pg->numV = nv;
  pg->numE = 0;

  for(i=0; i<nv; i++){
    ListInit(&(pg->adjList[i]));
    SetSortRule(&(pg->adjList[i]), WhoIsprecede);
  }
}
void graphDestroy(ALGraph *pg);
void addEdge(ALGraph *pg, int fromV, int toV);
void showGraphEdgeinfo(ALGraph *pg);
