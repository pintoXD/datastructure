#include <stdio.h>
#include <stdlib.h>


#define QUEUE_LENGHT 10


typedef struct queue
{

    int head;
    int tail;
    int lenght;
    int *array; //A very clever solution (for me). I'd never seen a dynamic array inside a struct.

} queue;


queue* createQueue(){

    queue* auxQueue = (queue*) malloc (sizeof(queue));

    auxQueue->array = (int *)malloc(sizeof(int) * QUEUE_LENGHT);

    auxQueue->head = -1;

    auxQueue->tail = 0;

    /*When head == tail, it means that the queue is empty*/




}


int enqueue(queue* q, int value){

    q->array[q->tail] = value;



    if(q->tail == q->lenght - 1){

         q->tail = 0;   

    }

    else{

        q->tail = q->tail + 1;
        
    }




}

int dequeue(queue* q){

    int aux = q->array[q->head];


    if(q->head == q->lenght - 1){
    
        q->head = 0;
    }

    else{

        q->head = q->head + 1;

    }


    return aux;


}

int isEmpty(stack *bender)
{

    if (bender->top_index == -1)
        return 1;
    else
        return 0;
}

int isFull(stack *bender)
{

    if (bender->top_index == STACK_HEIGHT - 1)
        return 1;
    else
    {
        return 0;
    }
}

int clearQueue(queue* q){


    free(q->array);

    free(q);

}





void main (){







}




