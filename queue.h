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
    //the location of this node
    unsigned int locationX;
    unsigned int locationY;
    //the next dir, like travelDir = NORTH;
    char travelDir;
}queueData;

// struct for the queue
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
 * descreption: init this queue
 * input:
 * output: a queue base
 */
queueBase* initQueueBase();

/**
 * descreption: push data into the queue
 * input: the queue base, data in unsigned int format
 * output: 0:success, 1 err
 */
int pushQueue(queueBase*, queueData);

/**
 * descreption: pop the top layer of this queue
 * input: the queue base
 * output: data in unsigned int
 */
queueData popQueue(queueBase*);

/**
 * descreption: get the length of this queue
 * input: the queue base
 * output: the length of this queue
 */
int getQueueLen(queueBase*);

/**
 * descreption: free all the space
 * input: the queue base
 * output: 0 success
 */
int freeQueue(queueBase*);

/**
 * descreption: error code
 */
#define QUEUEEMPTY 0xFFFFFFFF
#define QUEUEALLOCATIONERR 0x04