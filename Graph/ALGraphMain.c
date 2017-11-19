#include <stdio.h>
#include "ALbaseGraph.h"

int main(void){
  ALGraph graph;
  graphInit(&graph, 5);

  addEdge(&graph, A, B);
  addEdge(&graph, A, D);
  addEdge(&graph, B, C);
  addEdge(&graph, C, D);
  addEdge(&graph, D, E);
  addEdge(&graph, E, A);

  showGraphEdgeinfo(&graph);
  graphDestroy(&graph);
}
