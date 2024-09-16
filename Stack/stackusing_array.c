#include<stdio.h>
#include<stdlib.h>

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
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
};

int main(){


// requesting dynamic memory from the heap in the run time
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    s->arr[0] = 4;
    s->top = 0;

    
    if(isEmpty(s)){
    printf("The Stack is Empty\n");
}
else{
    printf("The Stack is not Empty\n");
};

if(isFull(s)){
    printf("The Stack is Full\n");
}
else{
    printf("The Stack is not Full\n");
}

return 0;
}


