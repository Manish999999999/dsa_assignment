// Question 2: Write a program to convert an infix expression to postfix expression and evaluate it using stack.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push into stack
void push(int value) {
    top++;
    stack[top] = value;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char opStack[MAX];
    int opTop = -1;

    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If opening bracket
        else if (ch == '(') {
            opStack[++opTop] = ch;
        }
        // If closing bracket
        else if (ch == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                postfix[j++] = opStack[opTop--];
            }
            opTop--; // remove '('
        }
        // If operator
        else {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(ch)) {
                postfix[j++] = opStack[opTop--];
            }
            opStack[++opTop] = ch;
        }
    }

    while (opTop != -1) {
        postfix[j++] = opStack[opTop--];
    }

    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int i;

    for (i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}
