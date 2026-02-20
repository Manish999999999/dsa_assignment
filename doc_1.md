# Question 1: Check Balanced Parentheses

## Data Structure Used
A stack is used to store opening brackets like (, { and [. Stack follows Last In First Out (LIFO) principle.

## Functions Description
- push(): Inserts an opening bracket into the stack.
- pop(): Removes the top element from the stack.
- isBalanced(): Checks each character of the expression and verifies whether the parentheses are balanced or not.

## Main Function
The main function takes an expression from the user and sends it to the isBalanced() function. Based on the returned value, it prints whether the expression is balanced or not.

## Sample Output
Enter an expression: a+(b-c)*d  
The expression has balanced parentheses.
