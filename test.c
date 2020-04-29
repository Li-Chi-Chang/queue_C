/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is queue
 * simply use push, pop
 * but befor using, please init a base, or it will has error
 * 
 * change the struct to:
typedef struct queueData
{
    int integer;
}queueData;
 * and run the test code
*/

#include <stdio.h>
#include "queue.h"

int main()
{
    printf("The testing file of queue\n");
    printf("Init a queue\n");
    queueBase* queue = initQueueBase();

    printf("push a data\n");
    queueData data;
    data.integer = 100;
    printf("\tpush a integer: %d\n",data.integer);
    pushQueue(queue,data);

    printf("push a data\n");
    queueData data1;
    data1.integer = 200;
    printf("\tpush a integer: %d\n",data1.integer);
    pushQueue(queue,data1);

    printf("push a data\n");
    queueData data2;
    data2.integer = 300;
    printf("\tpush a integer: %d\n",data2.integer);
    pushQueue(queue,data2);

    printf("get queue len: %d\n", getQueueLen(queue));

    printf("pop a data\n");
    queueData popdata = popQueue(queue);
    printf("\tthe data->integer %d\n", popdata.integer);

    printf("pop a data\n");
    queueData popdata1 = popQueue(queue);
    printf("\tthe data->integer %d\n", popdata1.integer);

    printf("free this queue\n");
    freeQueue(queue);

    printf("reach here means the functions work correctly\n");
    return 0;
}