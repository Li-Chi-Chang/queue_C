/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is queue
 * simply use push, pop
 * but befor using, please init a base, or it will has error
*/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int queueerr(int);

// init for this stack
queueBase* initQueueBase()
{
    queueBase* base = malloc(sizeof(queueBase));
    if(base == NULL)
        queueerr(QUEUEALLOCATIONERR);
    base->count = 0;
    base->next = NULL;
    return base;
}

/**
 * return 0: success
 * return 1: error on stack
 * */
int pushQueue(queueBase* base, queueData data)
{
    queueNode *newNode = (queueNode*) malloc(sizeof(queueNode));
    if(newNode == NULL)
    {
        return queueerr(QUEUEALLOCATIONERR);
    }
    newNode->next = NULL;
    newNode->data = data;

    if(base->count)
    {
        queueNode* node = base->next;
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = newNode;
    }
    else
    {
        base->next = newNode;
    }
    base->count++;
    return 0;
}

queueData popQueue(queueBase* base)
{
    queueData data;

    if(base->count)
    {
        queueNode* pointer = base->next;
        data = pointer->data;
        base->next = pointer->next;
        base->count--;
        free(pointer);
    }
    else
    {
        queueerr(QUEUEEMPTY);
        return data;
    }
    return data;
}

int getQueueLen(queueBase* base)
{
    return base->count;
}

int freeQueue(queueBase* base)
{
    while (base->count)
    {
        popQueue(base);
    }
    free(base);
    return 0;
}

int queueerr(int errcode)
{
    if(errcode == 0)
    {
        return 0;
    }

    printf("Error here.\nerr code: ");
    switch (errcode)
    {
    case QUEUEEMPTY:
        printf("%d QUEUE EMPTY!\n",errcode);
        break;
    case QUEUEALLOCATIONERR:
        printf("%d QUEUE ALLOCATION ERR!\n",errcode);
        break;
    default:
        printf("unknown %d\n",errcode);
    }
    exit(1);
}