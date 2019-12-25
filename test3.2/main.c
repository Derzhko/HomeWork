#include <stdio.h>
#include "priorityQueue.h"
#include <stdbool.h>

int main()
{
    int number = 0;
    PriorityQueue* myQueue = createQueue();
    while (true)
    {
        printf("0 - exit\n");
        printf("1 - add element in queue\n");
        printf("2 - pick an item from the queue\n");
        scanf("%d", &number);
        switch (number)
        {
            case 0:
            {
                deleteQueue(myQueue);
                return 0;
            }
            case 1:
            {
                int value = 0;
                int priority = 0;
                printf("insert value\n");
                scanf("%d", &value);
                printf("insert priority\n");
                scanf("%d", &priority);
                enqueue(value, priority, myQueue);
                break;
            }
            case 2:
            {
                printf("the item from the queue %d\n", dequeue(myQueue));
                break;
            }
        }
    }

}