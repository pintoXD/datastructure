#include <stdio.h>
#include <stdlib.h>
/*
Simple linked list example. 

A list with 3 nodes is created. Arbitrary values are assigned to them.

Then the list is printed using a dedicated function.

*/


typedef struct node{

    int data;
    struct node *next;


}list;



// void insert();
// void delete();
// void destroy();
void show(list *key);



void show(list *key){


    while(key != NULL){
        //Will all the nodes of this list.

        printf("Value of key: %d\n", key);

        printf("Value is: %d\n", key->data);

        key = key->next;

        printf("Value of key next is: %d\n", key);
    }



}



int main(){


    list *head = NULL;
    list *second = NULL;
    list *third = NULL;

    //Every node has to be their own space of memory
    //
    head = (list*) malloc (sizeof(list));
    second = (list*)malloc(sizeof(list));
    third = (list*)malloc(sizeof(list));


    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;


    show(head);














    printf("Peace among worlds _|_ !!!\n");

    printf("Teste\n");

}