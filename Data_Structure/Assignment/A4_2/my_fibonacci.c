#include <stdio.h>
#include <stdlib.h>
#include "../A3_2/my_math.h" 

long long fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    for (n = 5; n <= 44; n++) { // 최대 n 값을 바꿔가며 측정
        long long fn = fibonacci(n);
        long long fn_1 = fibonacci(n - 1);
        long long g = gcd(fn, fn_1);

        printf("n = %d, F(n) = %lld, F(n-1) = %lld, GCD = %lld\n", n, fn, fn_1, g);
    }

    return 0;
}