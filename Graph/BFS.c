#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_VERTEX 10

typedef int bool;
#define FALSE 0
#define TRUE 1

typedef struct graphNode{
  int vertex;
  struct graphNode *next;
} graphNode;

typedef struct graphType{
  int n;
  graphNode *adjList_H[MAX_VERTEX];
  int visited[MAX_VERTEX];
} graphType;

//큐연산
typedef struct Qnode{
  int data;
  struct Qnode *link;
} QNode;

//큐
typedef struct {
  QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue(){
  LQueueType *LQ;
  LQ = (LQueueType *)malloc(sizeof(LQueueType));
  LQ->front = NULL;
  LQ->rear = NULL;
  return LQ;
}

bool isEmpty(LQueueType *LQ){
  if(LQ->front == NULL){
    printf("\n Linked Queue is Empty !");
    return TRUE;
  } else return FALSE;
}

void enQueue(LQueueType *LQ, int item){
  QNode *newNode = (QNode *)malloc(sizeof(QNode));
  newNode->data = item;
  newNode->link = NULL;
  if(LQ->front == NULL){
    LQ->front = newNode;
    LQ->rear = newNode;
  }
}

int deQueue(LQueueType *LQ){
  QNode *old = LQ->front;
  int item;
  if(isEmpty(LQ)) {
    return FALSE;
  } else {
    item = old->data;
    LQ->front = LQ->front->link;
    if(LQ->front == NULL){
      LQ->rear = NULL;
    } free(old);
    return item;
  }
}

void createGraph(graphType *g){
  int v;
  g->n = 0;
  for(v=0; v < MAX_VERTEX; v++){
    g->visited[v] = FALSE;
    g->adjList_H[v] = NULL;
  }
}

void insertVertex(graphType *g, int v){
  if(((g->n)+1) > MAX_VERTEX){
    printf("\n 그래프 정점의 개수를 초과하였습니다!");
    return;
  }
  g->n++;
}

void insertEdge(graphType *g, int u, int v){
  graphNode *node;
  if(u>=g->n || v>=g->n){
    printf("\n 그래프에 없는 정접입니다!");
    return;
  }
  node = (graphNode *)malloc(sizeof(graphType));
  node->vertex = v;
  node->next = g->adjList_H[u];
  g->adjList_H[u] = node;
}

void print_adjList(graphType *g){
  int i;
  graphNode *p;
  for(i=0; i<g->n; i++){
    printf("\n\t\t 정점 %c의 인접 리스트", i +65);
    p = g->adjList_H[i];
    while(p){
      printf(" -> %c", p->vertex +65);
      p = p->next;
    }
  }
}

void BFS_adjList(graphType *g, int v){
  graphNode *w;
  LQueueType *Q;
  Q = createLinkedQueue();
  g->visited[v] = TRUE;
  printf(" %c", v +65);
  enQueue(Q, v);
  while(!isEmpty(Q)){
    v = deQueue(Q);
    for(w = g->adjList_H[v]; w; w=w->next){
      if(!g->visited[w->vertex]){
        g->visited[w->vertex] = TRUE;
        printf(" %c", w->vertex +65);
        enQueue(Q, w->vertex);
      }
    }
  }
}

int main(void){
  int i;
  graphType *G9;
  G9 = (graphType *)malloc(sizeof(graphType));
  createGraph(G9);

  for(i=0; i<7; i++)
    insertVertex(G9, 1);
  insertEdge(G9, 0, 2);
  insertEdge(G9, 0, 1);
  insertEdge(G9, 1, 4);
  insertEdge(G9, 1, 3);
  insertEdge(G9, 1, 0);
  insertEdge(G9, 2, 4);
  insertEdge(G9, 2, 0);
  insertEdge(G9, 3, 6);
  insertEdge(G9, 3, 1);
  insertEdge(G9, 4, 6);
  insertEdge(G9, 4, 2);
  insertEdge(G9, 4, 1);
  insertEdge(G9, 5, 6);
  insertEdge(G9, 6, 5);
  insertEdge(G9, 6, 4);
  insertEdge(G9, 6, 3);
  printf("\n G9의 인접리스트 ");
  print_adjList(G9);
  printf("\n\n//////////////\n\n너비우선탐색 >>");
  BFS_adjList(G9, 0);
}
