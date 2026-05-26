#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

extern int infixToPostfix(char* infix, char* postfix);
extern int evalPostfix(char* postfix);
extern int precedence(char op);

extern void printCharStack(ArrayStack* s);
extern void printIntStack(ArrayStack* s);
extern void printPostfix(char* postfix, int len);

extern void printTransform(ArrayStack* s, char* postfix, int len);