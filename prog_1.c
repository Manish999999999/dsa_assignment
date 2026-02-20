//Programme to check if an expression has balanced number of parantheses or not
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push element into stack
void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    }
}

// Function to pop element from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

// Function to check if parentheses are balanced
int isBalanced(char exp[]) {
    int i;
    char temp;

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                return 0;
            }

            temp = pop();

            if (exp[i] == ')' && temp != '(')
                return 0;
            if (exp[i] == '}' && temp != '{')
                return 0;
            if (exp[i] == ']' && temp != '[')
                return 0;
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    if (isBalanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression does NOT have balanced parentheses.\n");

    return 0;
}
