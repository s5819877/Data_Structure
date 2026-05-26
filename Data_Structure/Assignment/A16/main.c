#include "Calculator.h"

int main() {
	char infix[100], postfix[100];

	printf("입력 : ");
	fgets(infix, sizeof(infix), stdin);

	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == '\n') {
			infix[i] = '\0';
			break;
		}
	}

	infixToPostfix(infix, postfix);
	evalPostfix(postfix);
	
	return 0;
}