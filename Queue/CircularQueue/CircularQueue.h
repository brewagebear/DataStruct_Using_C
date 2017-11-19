#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUEUE_LEN 100
typedef int Data;

typedef struct _cQueue{
  int front;
  int rear;
  Data queArr[QUEUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);
int isEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data Qpeek(Queue *pq);


#endif
