#include <stdio.h>

int main() {
	float f;
	int x;

	printf("실수를 입력하세요 : ");
	scanf_s("%f", &f);

	x = f * 256;

	for (int i = 15; i >= 0; i--) {
		printf("%d", (x >> i) & 1);

		if (i == 8)
			printf(".");
	}

	return 0;
}