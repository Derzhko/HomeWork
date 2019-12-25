#include "priorityQueue.h"
#include <stdlib.h>

struct Element
{
    int value;
    int priority;
    Element* leftChild;
    Element* rightChild;
    Element* friend;
};

struct PriorityQueue
{
    Element* root;
};

PriorityQueue* createQueue()
{
    PriorityQueue* newQueue = malloc(sizeof(PriorityQueue));
    newQueue->root = NULL;
    return newQueue;
}

Element* createElement(int value, int priority)
{
    Element* newElement = malloc(sizeof(Element));
    newElement->leftChild = NULL;
    newElement->rightChild = NULL;
    newElement->friend = NULL;
    newElement->value = value;
    newElement->priority = priority;
    return newElement;
}

void add(int value, int priority, Element* element)
{
    if (priority > element->priority)
    {
        if (element->rightChild == NULL)
        {
            Element* newElement = createElement(value, priority);
            element->rightChild = newElement;
            return;
        }
        add(value, priority, element->rightChild);
    }
    else if (priority < element->priority)
    {
        if (element->leftChild == NULL)
        {
            Element* newElement = createElement(value, priority);
            element->leftChild = newElement;
            return;
        }
        add(value, priority, element->leftChild);
    }
    else
    {
        if (element->friend == NULL)
        {
            Element* newElement = createElement(value, priority);
            element->friend = newElement;
            return;
        }
        add(value, priority, element->friend);
    }
}

void enqueue(int value, int priority, PriorityQueue* queue)
{
    if (queue->root == NULL)
    {
        Element* element = createElement(value, priority);
        queue->root = element;
        return;
    }
    add(value, priority, queue->root);
}

int getElement(Element* element, Element* parentElement, PriorityQueue* queue)
{
    if (element->rightChild != NULL)
    {
        return getElement(element->rightChild, element, queue);
    }
    else if (element->friend != NULL)
    {
        int value = element->value;
        element->value = element->friend->value;
        Element* deleteElement = element->friend;
        element->friend = element->friend->friend;
        free(deleteElement);
        return value;
    }
    else if (element->leftChild != NULL)
    {
        int value = element->value;
        element->value = element->leftChild->value;
        element->priority = element->leftChild->priority;
        element->rightChild = element->leftChild->rightChild;
        element->friend = element->leftChild->friend;
        element->leftChild = element->leftChild->leftChild;
        return value;
    }
    int value = element->value;
    free(element);
    if (parentElement != NULL)
    {
        if (parentElement->priority < element->priority)
        {
            parentElement->rightChild = NULL;
        }
        else
        {
            parentElement->leftChild = NULL;
        }
    }
    else
    {
        queue->root = NULL;
    }
    return value;
}

int dequeue(PriorityQueue* queue)
{
    if (queue->root == NULL)
    {
        return -1;
    }
    return getElement(queue->root, NULL, queue);
}

void deleteElement(Element* element)
{
    if (element == NULL)
    {
        return;
    }
    deleteElement(element->rightChild);
    deleteElement(element->friend);
    deleteElement(element->leftChild);
    free(element);
}

void deleteQueue(PriorityQueue* queue)
{
    deleteElement(queue->root);
    free(queue);
}