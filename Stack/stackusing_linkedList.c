#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


// here we are going create stack using the Linked List 
//  This means here we are going to perform stack's functions like push, pop ,isfull, isempty in here.

int isEmpty(struct Node *head){
    if( head->next== NULL){
        return 1;
}
else{
    return 0;
}
}

// checking the memory is full by allocating the memory dynamically.
int isFull(struct Node *head){
    
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t== NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Node **head, int number){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t== NULL){
        printf("Stack Overflow\n");
    }
    else{
        t->data = number;
        t->next = *head;
        *head = t ;
    }
}


// printing the Elements in the linked list

void printList(struct Node *ptr) {
    printf("\n");
    while(ptr!= NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
        
    }
}


int main(){

    struct Node * head;
    struct Node * second;
    struct Node * third;

// Requesting the space in the heap.
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

// storing and linking of the nodes
head->data = 7;
head->next = second;


// linking the second and third nodes
second->data = 8;
second->next = third;


// terminating the linked list
third->data = 9;
third->next = NULL;

printList(head);

// Passing the argument in this manner will just send a copy it won't make changes here 

// so Sending it in a different manner like below will help
push(&head,88);

printList(head);
return 0;
}







