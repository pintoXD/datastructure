/*
    This was coded just for fun.

    This code will present an impletation of a linked list,
    plus the basic operations of insert, show, delete and some
    advanced operations like insert/delete at the start, end or arbritary 
    position.

*/

#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data;
    struct node *next;
}node;

void create(node *key);
void insert(node **head_ref, int new_value);
void delete();
void show();
void destroy();


void create(node *key){
    key = (node*) malloc (sizeof(node));

    key->data = 0;
    key->next = NULL;

}


void insert(node **head_ref, int new_value){

    node *temp = (node*) malloc (sizeof(node));

    temp->data = new_value;
    temp->next = (*head_ref);

    *head_ref = temp;
    
}


void delete(node **head_ref){

    //Function that delete the last node of the list
    //Suppose that the last node is linked to NULL
    node *temp = *head_ref;
    node *prev = NULL;


        
    while(temp->next != NULL){
        prev = temp;    
        temp = temp->next;

   
   }


    prev->next = temp->next;

    free(temp);



}




void main(){

    node *head = NULL;









}









