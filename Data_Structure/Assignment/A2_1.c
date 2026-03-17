/*
#include <stdio.h>

int main() {
    float num;
    int sign;
    int exponent = 0;
    float fraction;

    // 입력
    printf("실수를 입력하세요 : ");
    scanf_s("%f", &num);

    // 1️⃣ 부호
    if (num < 0) {
        sign = 1;
        num = -num;
    }
    else {
        sign = 0;
    }

    // 2️⃣ 정규화 (1.x 형태 만들기)
    fraction = num;

    if (fraction >= 2.0) {
        while (fraction >= 2.0) {
            fraction /= 2.0;
            exponent++;
        }
    }
    else if (fraction < 1.0) {
        while (fraction < 1.0) {
            fraction *= 2.0;
            exponent--;
        }
    }

    // 3️⃣ 지수에 bias(127) 더하기
    int exp_bits = exponent + 127;

    // 4️⃣ 가수 (소수점 이하만 추출)
    fraction -= 1.0;

    // 출력 시작
    printf("%d/", sign);

    // 지수 출력 (8비트)
    for (int i = 7; i >= 0; i--) {
        printf("%d", (exp_bits >> i) & 1);
        if (i == 4) printf(" ");
    }
    printf("/");

    // 가수 출력 (23비트)
    for (int i = 0; i < 23; i++) {
        fraction *= 2;
        if (fraction >= 1.0) {
            printf("1");
            fraction -= 1.0;
        }
        else {
            printf("0");
        }

        if (i % 4 == 3) printf(" ");
    }

    return 0;
}
*/