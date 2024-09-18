#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// we are going to code an algorithm where it would help us to check whether the stack is empty or not.

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}


// This Function helps you to push the elements into the stack 
void push(int value,struct stack *s) {

    if(isFull(s)){
    printf("The Stack is Full\n");
}
else{
    s->top++;
    s->arr[s->top] = value;
}
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("The Stack is Empty\n");
        return -1;
    }
    else{
        int old_Top = ptr->arr[ptr->top];
        ptr->top--;
        return old_Top;
    }   
}

int main(){


// requesting dynamic memory from the heap in the run time
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    s->arr[0] = 4;
    s->top = 0;

    int value = 30;

printf("Before pushing, Full: %d\n", isFull(s));
printf("Before pushing, empty: %d\n", isEmpty(s));


// pushing the eelements into the stack

push(30,s);
push(40,s);
push(32,s);
push(33,s);
push(35,s);
push(36,s);
push(37,s);
push(39,s);

printf("After pushing full : %d\n",isFull(s));
printf("After pushing Empty : %d\n",isEmpty(s));

// now using the Pop function



printf("Popped %d from the stack\n", pop(s)); 
return 0;

}


