#include <stdio.h>

int main() {
    float num;
    int sign;
    int x = 0;
    float f;

    scanf_s("%f", &num);

    if (num < 0) {
        sign = 1;
        num = -num;
    }
    else {
        sign = 0;
    }

    f = num;

    if (f >= 2.0) {
        while (f >= 2.0) {
            f /= 2.0;
            x++;
        }
    }
    else if (f < 1.0) {
        while (f < 1.0) {
            f *= 2.0;
            x--;
        }
    }

    int y = x + 127;

    f -= 1.0;

    printf("%d / ", sign);

    for (int i = 7; i >= 0; i--) {
        printf("%d", (y >> i) & 1);
    }
    printf(" / ");

    for (int i = 0; i < 23; i++) {
        f *= 2;
        if (f >= 1.0) {
            printf("1");
            f -= 1.0;
        }
        else {
            printf("0");
        }
    }

    return 0;
}
