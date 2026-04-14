#include <stdio.h>
#define NUM 49 //NUM을 증가시키며 측정

long long fibo(long long n) {
	if (n <= 2) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	long long n = fibo(NUM);
	printf("%lld\n", n);

	return 0;
}