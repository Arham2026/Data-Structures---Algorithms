#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// using an array
struct stack {
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack* sp){
    return sp->arr[0];
}


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

void push(char x, struct stack *s) {
    if (s->top == s->size - 1) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = x;
    }
}

char pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack is empty and Unbalanced Statement\n");

        return '\0';  // return null character if stack is empty
    } else {
        char popped_element = s->arr[s->top];
        s->top--;
        return popped_element;
    }

    return 0;
}


int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isoperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
        return 1;
    }
    else{
        return 0;
    }
}


char * infixtopostfix(char * infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char)) ;

    int i =0;
    int j =0;

    while(infix[i] != '\0'){
        if(!isoperator(infix[i])){
            postfix[j] = infix[i];
            i++,j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(infix[i], sp);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while(!isEmpty(sp)){
    postfix[j] = pop(sp);
    j++;
}
postfix[j] = '\0';
return postfix;
}



int main() {
   
   char * infix = "a-b*o/8";
   printf("%s",infixtopostfix(infix));
    return 0;
}














