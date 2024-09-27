#include<stdio.h>
#include<stdlib.h>

// using an array
struct stack{
    int size;
    int top;
    char *arr;
};



void push(char x,struct stack *s){
    if(s->top==s->size-1){
        printf("Stack is full");
    }
    else{
        s->top++;
        s->arr[s->top]=x;
    }
}


char pop(char x,struct stack *s){
    

     if(s->top == -1){
        printf("Stack is empty");
        return 'empty';
    }
    else{
       int poped_element = s->top--;
        return s->arr[poped_element];
    }
}


void check(char x,struct stack *s){
    if(x=='('){
        push(x,s);
    }
    else if(x==')'){
        char element_popped = pop(x,s);
        printf("%c",element_popped);
    }
}

int main(){

    // here we are going to code a solution where we are going to check whether the given statement has balanced paranthesis or not

    // dynamically allocating the memory 
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    // assigning the values

    s->size = 20;
    s->top = -1;
    // intially we assign the top to -1

    s->arr = (char *)malloc((s->size)* sizeof(char));
    // here we are allocating the memory for the array of the stack
    
    s->arr[0] = 7;
    s->top = 0;

    // now using the push function to push the value in the stack but this push system is a custom push system.
    check('7',s);
    check('(',s);
    check('(',s);
    check(')',s);
    check('9',s);
    check('k',s);


    return 0;
}

// worked out NEED TO optimize the code and Complete the concepts soon so that I can work on different projects
