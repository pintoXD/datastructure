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
void delete (node **head_ref);
void show(node *head_ref);
// void destroy();


void create(node *key){

    //Create a list
    //Is this really needed??
    key = (node*) malloc (sizeof(node));

    key->data = 0;
    key->next = NULL;

}


void insert(node **head_ref, int new_value){

    //Insert elements before the head of the list

    node *temp = (node*) malloc (sizeof(node));

    temp->data = new_value;
    temp->next = (*head_ref);

    *head_ref = temp;
    
}



void insert_after(node *temp, int value, int new_value){
    //Insert element after another
    //value is the value to search
    //new_value is just the new element to insert
    //Pretty obvious, I think

    // node *temp = *temp;
    node *new_node = (node*) malloc(sizeof(node));

    while (temp->next != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    //This if checks if the desired value is at the 
    //end of que list. Could be happen :v
    if(temp->next == NULL && temp->data == value){
        temp->next = new_node;
        new_node->data = new_value;
        new_node->next = NULL;
        printf("Insert done");
    }   
    else if(temp->data == value){ 

        new_node->data = new_value;
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Insert done");
    }
    else
       printf("Insert unsuccessful. Value not found");


}


void insert_at_end(node *temp, int new_value){

    node *prev; //To keep track of the previous node

    node *new_node = (node*) malloc (sizeof(node));

    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = new_node;
    new_node->data = new_value;
    new_node->next = temp;
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

void delete_first(node **head_ref){

    node *temp = *head_ref;

    *head_ref = temp->next;

    free(temp);

 }

void delete_element(node **head_ref, int value){
    //This function will search for the node with the given value, then delete it
    node *prev = NULL;
    node *temp = *head_ref;

    // printf("Before while statement");

    while(temp->next != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    // printf("After while statement");

    if(prev == NULL){//In case of the node be the first. Maybe happen :v
    
        delete_first(head_ref);
    }

    //This "IF" checks if the desired value is at the
    //end of que list. Could be happen :v
    if (temp->next == NULL && temp->data == value){

        prev->next = NULL;

        free(temp);
    }
    else if (temp->data == value){
        // printf("Here. Trying do delete.");

        prev->next = temp->next;

        free(temp);


    }
    else
        printf("Value not found. Delete unsuccessful.\n");


}


void show(node *head_ref){

    printf("Showing elements in queue:\n");

    while(head_ref != NULL){
        
        printf("%d ", head_ref->data);

        head_ref = head_ref->next;
    }

    printf("\n");

}




void main(){

    node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);

    show(head);

    delete(&head);
    delete(&head);

    printf("\nAfter delete\n");
    show(head);
    printf("\n");

    printf("\nAfter delete first\n");
    delete_first(&head);
    show(head);
    printf("\n");

    printf("\nAfter insert_after\n");
    insert_after(head, 6, 7);
    show(head);
    printf("\n");

    printf("\nAfter insert_at_end\n");
    insert_at_end(head, 8);
    show(head);
    printf("\n");

    printf("\nAfter delete_element\n");
    delete_element(&head, 9);
    show(head);
    printf("\n");


}









