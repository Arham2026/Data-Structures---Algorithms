#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

// / Traversing the function and printing the values of the linked list 

void printList(struct Node *ptr) {
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
return 0;
}