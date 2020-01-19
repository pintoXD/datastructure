#include <stdio.h>
#include <stdlib.h>

#define QUEUE_LENGHT 4

/*
    This is an implementation of a queue as presented in Cormen's book,
    with some modifications, made to fit the circularity specification,
    that is required in the book.

*/

typedef struct queue{

    int head;
    int tail;
    int totalLength;
    // int currentLength; //This is only needed if the queue is circular.
    int *array; //A very clever solution (for me). I'd never seen a dynamic array inside a struct.

} queue;

queue *createQueue(){

    queue *auxQueue = (queue *)malloc(sizeof(queue));

    auxQueue->array = (int *)malloc(sizeof(int) * QUEUE_LENGHT);

    auxQueue->head = -1;

    auxQueue->tail = -1;

    auxQueue->totalLength = QUEUE_LENGHT;


    /*When head == tail, it means that the queue is empty*/
}

int enqueue(queue *q, int value){


    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }

    if (q->head == -1)
        q->head = 0;

    if(q->tail == -1)
        q->tail=0;

    q->array[q->tail] = value;

    if (q->tail == q->totalLength - 1) {

        q->tail = -1;
    }

    else{

        q->tail = q->tail + 1;
    }


    // q->currentLength++;
}

int dequeue(queue *q){



    int aux = q->array[q->head]; 


    if(isEmpty(q)){
        printf("Queue empty\n");
        return 999;
    }



    if (q->head == q->totalLength - 1){

        q->head = -1;
    }

    else{

        q->head = q->head + 1;
    }

    // q->currentLength--;

    return aux;
}

int isEmpty(queue *q){

    if (q->head == q->tail)
        return 1;
    else
        return 0;
}

int isFull(queue *q){
    /* In the Cormen's book, he says that if 
    queue.head = q.tail + 1, so the queue is full.

    
    */
    // if (q->currentLength  == q->totalLength)
    if (q->head == q->tail + 1)
        return 1;
    else
    {
        return 0;
    }

}

int printQueue(queue* q){
    int index = q->head;
    int tail = q->tail;
    printf("Queue content: ");

    if(isEmpty(q)){
        printf("The queue is empty");
        return 0;
    }

    if(tail == -1){

        tail = q->totalLength;

    }

    while (index != tail)
    {

        if (index > q->totalLength){
            index = 0;
        }

        printf("queue[%d] = %d ", index, q->array[index]);

        index = index + 1;
    }
}


int clearQueue(queue *q){

    free(q->array);

    free(q);
}

void main(){

    /*
        This is a circular queue, wich means that a queue,
        with a length of 4, could have its start index at array[2]
        and its end index at array[1]. 
    
    */


    queue* testQ = createQueue();

    enqueue(testQ, 2);
    printf("\nCurrent Head: %d\n", testQ->head);
    printf("Current Tail: %d\n\n", testQ->tail);

    enqueue(testQ, 3);
    printf("\nCurrent Head: %d\n", testQ->head);
    printf("Current Tail: %d\n\n", testQ->tail);

    enqueue(testQ, 9);
    printf("\nCurrent Head: %d\n", testQ->head);
    printf("Current Tail: %d\n\n", testQ->tail);

    enqueue(testQ, 7);
    printf("\nCurrent Head: %d\n", testQ->head);
    printf("Current Tail: %d\n\n", testQ->tail);

    enqueue(testQ, 7);
    printQueue(testQ);
    printf("\nDeuqueing: %d\n", dequeue(testQ));
    printf("Deuqueing: %d\n", dequeue(testQ));
    printf("Deuqueing: %d\n", dequeue(testQ));

    printf("\nCurrent Head: %d\n", testQ->head);
    printf("Current Tail: %d\n\n", testQ->tail);
    printf("Deuqueing: %d\n", dequeue(testQ));
    printf("Deuqueing: %d\n", dequeue(testQ));


    // printf("Deuqueing: %d\n", dequeue(testQ));

    printf("Current Head Before 15: %d\n", testQ->head);
    printf("Current Tail Before 15: %d\n\n", testQ->tail);

    // printQueue(testQ);

    enqueue(testQ, 15);

    printf("\nCurrent Head After 15: %d\n", testQ->head);
    printf("Current Tail After 15: %d\n\n", testQ->tail);

    // enqueue(testQ, 27);

    printQueue(testQ);




    clearQueue(testQ);



}
