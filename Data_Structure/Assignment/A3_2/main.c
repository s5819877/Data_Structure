#include <stdio.h>
#include "my_math.h"

int main() {
    long long a, b;

    printf("두 정수를 입력하세요: ");
    if (scanf_s("%lld %lld", &a, &b) != 2) {
        printf("입력 오류: 숫자를 두 개 입력하세요.\n");
        return 1;
    }

    long long g = gcd(a, b);
    long long l = lcm(a, b);

    if (g == -1)
        printf("GCD 정의 불가 (두 수 모두 0)\n");
    else
        printf("GCD: %lld, LCM: %lld\n", g, l);

    return 0;
}