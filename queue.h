/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is queue
 * simply use push, pop
 * but befor using, please init a base, or it will has error
*/

typedef struct queueData
{
    int integer;
}queueData;

// struct for the stack
typedef struct queueNode
{
    queueData data;
    struct queueNode *next;
}queueNode;

typedef struct
{
    unsigned int count;
    struct queueNode *next;
}queueBase;

/**
 * descreption: init this stack
 * input:
 * output: a stack base
 */
queueBase* initQueueBase();

/**
 * descreption: push data into the stack
 * input: the stack base, data in unsigned int format
 * output: 0:success, 1 err
 */
int pushQueue(queueBase*, queueData);

/**
 * descreption: pop the top layer of this stack
 * input: the stack base
 * output: data in unsigned int
 */
queueData popQueue(queueBase*);

/**
 * descreption: get the length of this stack
 * input: the stack base
 * output: the length of this stack
 */
int getQueueLen(queueBase*);

/**
 * descreption: free all the space
 * input: the stack base
 * output: 0 success
 */
int freeQueue(queueBase*);

/**
 * descreption: error code
 */
#define QUEUEEMPTY 0xFFFFFFFF
#define QUEUEALLOCATIONERR 0x04