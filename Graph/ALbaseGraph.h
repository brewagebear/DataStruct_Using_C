#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "../linkedList2/linkedList.h"

enum {A, B, C, D, E, F, G, H, I, J}; //vertax 선언

typedef struct _ual{
  int numV;
  int numE;
  List *adjList;
} ALGraph;

void graphInit(ALGraph *pg, int nv);
void graphDestroy(ALGraph *pg);
void addEdge(ALGraph *pg, int fromV, int toV);
void showGraphEdgeinfo(ALGraph *pg);

#endif
