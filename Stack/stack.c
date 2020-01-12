#include <stdio.h>
#include <stdlib.h>

#define STACK_HEIGHT 5

/*
    This is a thin implementation of a stack data structure.

    The struct below, was copied from the Geeks For Geeks website, 
    because it was much more better than my implementation. I would
    never think to do a struct this way. 


    About the functions, some of it I took the idea from the Cormem's book...
    And from the voices in my head.


*/

typedef struct stack{

int top_index;
int height;
int* array; //A very clever step (for me). I'd never seen a dynamic array inside a struct. 

}stack;


stack* createStack();
int push(stack *bender, int value);
int pop(stack* bender);
int isEmpty(stack* bender);





stack* createStack(){

    stack* aux = (stack*) malloc (sizeof(stack));

    aux->array = (int*) malloc(sizeof(int) * STACK_HEIGHT);

    aux->top_index = -1;


    return aux;
}

int isEmpty(stack* bender){

    if (bender->top_index == -1)
        return 1;
    else
        return 0;
    
}



int isFull(stack* bender){

    if(bender->top_index == STACK_HEIGHT - 1)
        return 1;
    else
    {
        return 0;
    }
    
}




int push(stack* bender, int value){

    
    if(isFull(bender)){
        printf("Stack full. Stack overflow!");
        return 0;

    }


    bender->top_index = bender->top_index + 1;
    bender->array[bender->top_index] = value;

    return 1;

}


int pop(stack* bender)
{
    
    if(isEmpty(bender)){
        printf("Stack already empty. Underflow");

        return 0;
    }

    // printf("\nCurrent Top: %d", bender->top_index);

    bender->top_index = bender->top_index - 1;
    
    return bender->array[bender->top_index + 1];
    


}



int clearStack(stack* fry){

    for(int i = 0; i < STACK_HEIGHT; i++){
        fry->array[i] = NULL;
    }

    fry->top_index = -1;



}


void main(){

    
    int stackTop;
    stack* morty = createStack();
   

    push(morty, 2);
    push(morty, 3);
    push(morty, 9);
    push(morty, 7);

    printf("Current top: %d", morty->top_index);

    printf("\nStack content: ");
    for(int i = 0; i < morty->top_index + 1; i++){

        printf("%d ", morty->array[i]);

    }
    
    
    printf("\n\nPopping...\nPopped %d from stack", pop(morty));
    printf("\n\nPopping...\nPopped %d from stack", pop(morty));

    printf("\nStack content: ");
    for (int i = 0; i < morty->top_index + 1; i++){

        printf(" %d\n", morty->array[i]);
    }

    printf("\nHello world\n\n");

    clearStack(morty);
    free(morty);

    

}

