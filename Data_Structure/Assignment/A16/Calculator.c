#include "Calculator.h"
#include <string.h>

int infixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	printf("Transform : \n");

	for (int i = 0; infix[i] != NULL; i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j] = infix[i];
			j++;
			printTransform(opStack, postfix, j);
		}
		else if (infix[i] == '+' || infix[i] == '-' ||
			infix[i] == '*' || infix[i] == '/') {

			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);

				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					postfix[j] = popArrayStack(opStack).operator;
					j++;
				}
				else {
					break;
				}
			}
			stackElement item;
			item.operator = infix[i];
			pushArrayStack(opStack, item);
			printTransform(opStack, postfix, j);
		}
		else if (infix[i] == '(') {
			stackElement item;
			item.operator = infix[i];
			pushArrayStack(opStack, item);
			printTransform(opStack, postfix, j);
		}
		else if (infix[i] == ')') {
			do
			{
				stackElement prevOp = popArrayStack(opStack);

				if (prevOp.operator != '(') {
					postfix[j] = prevOp.operator;
					j++;
				}
				if (prevOp.operator == '(') {
					break;
				}
			} while (!emptyArrayStack(opStack));
			printTransform(opStack, postfix, j);
		}
	}

	while (!emptyArrayStack(opStack)) {
		postfix[j] = popArrayStack(opStack).operator;
		j++;
	}

	postfix[j] = NULL;
	printTransform(opStack, postfix, j);
	printf("\n- Result : ");
	printPostfix(postfix, j);
	printf("\n");

	destroyArrayStack(opStack);
	return 0;
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;

	printf("\nEval : \n");
	printf("- Postfix : ");
	for (int k = 0; postfix[k] != NULL; k++) {
		if (k > 0)
			printf(" ");
		printf("%c", postfix[k]);
	}
	printf("\n");

	while (postfix[i] != NULL) {
		if (postfix[i] == ' ') {
			i++;
			continue;
		}
		
		stackElement item;
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			item.value = (int)(postfix[i] - '0');
			pushArrayStack(valueStack, item);
		}
		else if (postfix[i] == '*') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			item.value = i2 * i1;
			pushArrayStack(valueStack, item);
		}
		else if (postfix[i] == '/') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			item.value = i2 / i1;
			pushArrayStack(valueStack, item);
		}
		else if (postfix[i] == '+') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			item.value = i2 + i1;
			pushArrayStack(valueStack, item);
		}
		else if (postfix[i] == '-') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			item.value = i2 - i1;
			pushArrayStack(valueStack, item);
		}
		printf("- Current : %c | Stack : ", postfix[i]);
		printIntStack(valueStack);
		printf("\n");

		i++;
	}

	int result = popArrayStack(valueStack).value;
	printf("\n- Result : %d\n", result);

	destroyArrayStack(valueStack);
	return result;
}

int precedence(char op) {
	switch (op)
	{
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	default:
		return 0;
	}
}

void printCharStack(ArrayStack* s) {
	for (int i = 0; i <= s->top; i++) {
		if (i > 0) 
			printf(" ");
		printf("%c", s->data[i].operator);
	}
}

void printIntStack(ArrayStack* s) {
	for (int i = 0; i <= s->top; i++) {
		if (i > 0) 
			printf(" ");
		printf("%d", s->data[i].value);
	}
}

void printPostfix(char* postfix, int len) {
	for (int i = 0; i < len; i++) {
		if (i > 0) 
			printf(" ");
		printf("%c", postfix[i]);
	}
}

void printTransform(ArrayStack* s, char* postfix, int len) {
	printf("- Postfix : ");
	printPostfix(postfix, len);
	printf(" | Stack : ");
	printCharStack(s);
	printf("\n");
}