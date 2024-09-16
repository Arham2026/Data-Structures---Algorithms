#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

// Traversing the function and printing the values of the linked list 

void printList(struct Node *ptr) {
    printf("\n");
    while(ptr!= NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
        
    }
}

struct Node *DeleteFirst(struct Node *head){
     struct Node *temp = head;
     head = head->next;
     free(temp);

return head;
}

// delete the node in between the array.
struct Node *DeleteInbetween(struct Node *head,int index){
    struct Node *p = head;
    int i;
    while(i!=index-1){
     p = p->next;
     i++;
    }

struct Node *q = p->next;
p->next = q->next;
free(q);
return head;
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

// printList(head);
// head = DeleteFirst(head);
printList(head);
head = DeleteInbetween(head,1);
printList(head);


return 0;
}