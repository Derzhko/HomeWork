#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

typedef struct PriorityQueue PriorityQueue;
typedef struct Element Element;

PriorityQueue* createQueue();
void enqueue(int value, int priority, PriorityQueue* queue);
int dequeue(PriorityQueue* queue);
void deleteQueue(PriorityQueue* queue);

#endif //PRIORITYQUEUE_H
