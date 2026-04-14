#include <stdio.h>
#define NUM 3000000000 //NUM을 증가시키며 측정

long long fibo(long long n) {
	long long f1 = 1;
	long long f2 = 1;

	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		long long fn;

		for (int i = 3; i <= n; i++) {
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		return fn;
	}
}

int main() {
	long long n = fibo(NUM);
	printf("%lld\n", n);

	return 0;
}