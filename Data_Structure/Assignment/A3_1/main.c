#include <stdio.h>
#include "my_fraction.h"

int main() {
    char s1[50], op[5], s2[50];

    scanf_s("%49s %4s %49s", s1, 50, op, 5, s2, 50);

    Fraction f1 = create_from_string(s1);
    Fraction f2 = create_from_string(s2);
    Fraction result;

    switch (op[0]) {
    case '+':
        result = add(f1, f2);
        break;
    case '-':
        result = sub(f1, f2);
        break;
    case '*':
        result = mul(f1, f2);
        break;
    case '/':
        result = div_frac(f1, f2);
        break;
    default:
        printf("잘못된 연산자입니다.\n");
        return 1;
    }

    print_fraction(result);

    return 0;
}