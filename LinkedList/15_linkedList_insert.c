#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


// / Traversing the function and printing the values of the linked list 

void printList(struct Node *ptr) {
    printf("\n");
    while(ptr!= NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
        
    }
}


// How to insert the node initially 

struct Node *Insert_initial(struct Node *head,int number){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = number;

    return ptr;
}

// Inserting in between the Nodes
struct Node *InsertInBetween(struct Node *head,int number,int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    
//storing the head in a pointer
   struct Node * p = head;
   int i=0;

// travelling through the node before the destinated index.
   while(i!=index-1){
    // 
    p = p->next;
    i++;
   }

ptr->data = number;
// points to the next element in the array
ptr->next = p->next;

// cuts the bond with the original array and joins with the inserting node
p->next = ptr;

return head;
}

struct Node *Insert_atEnd(struct Node *head,int number){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data = number;
    p->next = ptr;
    ptr->next = NULL;
    
    return head;
}

struct Node *Insert_After_Node(struct Node *head,struct Node *prevNode,int number){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = number;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
        
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
// head = Insert_initial(head,78);
// InsertInBetween(head,56,1);
// printList(head);
// Insert_atEnd(head,79);
printList(head);
head = Insert_After_Node(head,second,56);
printList(head);

return 0;
}