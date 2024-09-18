#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
//  peek returns the 
int peek(struct stack *s, int i){
    int arrayInd = s->top-i+1;
    // position & index are not same, i is the position
    // relation => top-i+1 

    if(( arrayInd) < 0){
        printf("Invalid position\n");
        return -1;
    }
    else{
        return s->arr[arrayInd];
    }
}

// stack Top and Bottom

int stack_Top(struct stack *s){
    if(isEmpty(s)){
        return -1;
    }
    else{
        return s->arr[s->top];
    }
}

int stack_Bottom(struct stack *s){
    if(isEmpty(s)){
        return -1;
    }
    else{
        return s->arr[0];
    }
}



int main(){

struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    s->arr[0] = 4;
    s->top = 0;

    push(30,s);
    push(33,s);
    push(69,s);

printf("Before pushing, Full: %d\n", isFull(s));
printf("Before pushing, empty: %d\n", isEmpty(s));


int peeks = peek(s,4);
printf("the requested number is %d\n",peeks);

int top = stack_Top(s);
printf("The Number at the Top of the Stack is %d\n",top);

int Bottom = stack_Bottom(s);
printf("The Number at the Bottom of the Stack is %d ",Bottom);

return 0;
}