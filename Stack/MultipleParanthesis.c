#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// using an array
struct stack {
    int size;
    int top;
    char *arr;
};


void push(char x, struct stack *s) {
    if (s->top == s->size - 1) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = x;
    }
    return;
}


// for pop

char pop(struct stack *s, char x,int j) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return '\0';  // return null character if stack is empty
    } else{
        char popped_element = s->arr[s->top];
        if(popped_element == '(' && x==')' 
        || popped_element == '[' && x==']'
        || popped_element == '{' && x=='}'){
        s->top--;
        return popped_element;
        }
        else{
            return 1;
        }
    }

}

void check(const char *expression, struct stack *s) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(expression[i], s);
        } 
        
       else if (expression[i] == '[') {
            push(expression[i], s);
        } 

        else if (expression[i] == '{') {
            push(expression[i], s);
        } 

        else if (expression[i] == ')') {

            char element_popped = pop(s,')',i);

            // here we should match whether the popping element is the right match for the paranthesis
            printf("Popped element: %c\n", element_popped);
        }
        else if (expression[i] == '}') {

            char element_popped = pop(s,'}',i);

            // here we should match whether the popping element is the right match for the paranthesis
            printf("Popped element: %c\n", element_popped);
        }

         else if (expression[i] == ']') {

            char element_popped = pop(s,']',i);

            // here we should match whether the popping element is the right match for the paranthesis
            printf("Popped element: %c\n", element_popped);
        }

    }
}



int main() {
    // Here we are going to code a solution to check whether the given statement has balanced parentheses or not.

    // Dynamically allocating the memory
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    
    // Assigning the values
    s->size = 20;
    s->top = -1;  // initially, we assign the top to -1
    
    // Allocating memory for the array of the stack
    s->arr = (char *)malloc(s->size * sizeof(char));

    // Example expression to check
  const char * expression = "[((9)+k)]}";

    check(expression, s);

    return 0;
}

// Finally the right Code








