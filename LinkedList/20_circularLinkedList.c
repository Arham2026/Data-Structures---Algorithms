#include<stdio.h>
#include<stdlib.h>

struct Node {
        int data;
        struct Node* next;
    };

// printing the circular linked list
void circularLinkedList(struct Node *head){
    struct Node * ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=head);
}

// insertion of a node in the circular linked list
struct Node * InsertionatFirst(struct Node * head, int data){

    struct Node *ptr2 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr2->data = data;
    while(p->next!=head){
        p = p->next;
    }
    // the last element of the linked list 
    p->next = ptr2;
    ptr2->next = head;
    head = ptr2;
    return head;
}


int main(){

struct Node * head;
struct Node * second;
struct Node * third;
struct Node * fourth;

head   = (struct Node *) malloc(sizeof(struct Node));
second = (struct Node *) malloc(sizeof(struct Node));
third  = (struct Node *) malloc(sizeof(struct Node));
fourth = (struct Node *) malloc(sizeof(struct Node));

head->data = 4;
head->next = second;

second->data = 5;
second->next = third;

third->data = 7;
third->next = fourth;

fourth->data = 8;
fourth->next = head;

circularLinkedList(head);
head = InsertionatFirst(head,78);
circularLinkedList(head);
// Element Inserted bruh!

return 0;
}