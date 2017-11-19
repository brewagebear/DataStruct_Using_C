#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__


typedef int BOOL;
#define FALSE 0
#define TRUE  1

BOOL b;

typedef int Data;

typedef struct _node{
  Data data;
  struct _node *next;
} Node;

typedef struct _LQueue{
  Node *front;
  Node *rear;
} LQueue;

typedef LQueue Queue;

void queueInit(Queue *pq);
BOOL isEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data Qpeek(Queue *pq);
#endif
