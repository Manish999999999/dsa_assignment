# Question 2: Infix to Postfix Conversion and Evaluation

## Data Structure Used
Stack is used to store operators during infix to postfix conversion and also to evaluate the postfix expression.

## Functions Description
- push(): Pushes a value into the stack.
- pop(): Removes and returns the top value from the stack.
- precedence(): Returns priority of operators.
- infixToPostfix(): Converts infix expression into postfix expression.
- evaluatePostfix(): Evaluates the postfix expression using stack.

## Main Function
The main function takes an infix expression from the user, converts it into postfix form, and then evaluates the postfix expression. Finally, it prints both postfix expression and the result.

## Sample Output
Enter infix expression: (3+5)*2  
Postfix expression: 35+2*  
Evaluation result: 16