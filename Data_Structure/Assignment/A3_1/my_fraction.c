#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my_fraction.h"

long long get_gcd(long long a, long long b) {
    a = llabs(a); 
    b = llabs(b);
    while (b) {
        a %= b;
        long long temp = a; 
        a = b; 
        b = temp;
    }
    return a;
}

Fraction simplify(Fraction f) {
    if (f.den == 0) {
        fprintf(stderr, "Error: 분모가 0일 수 없습니다.\n");
        exit(1);
    }
    if (f.num == 0) 
        return (Fraction) { 0, 1 };

    long long common = get_gcd(f.num, f.den);
    f.num /= common;
    f.den /= common;

    if (f.den < 0) { 
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}

Fraction create_from_string(char* str) {
    Fraction f = { 0, 1 };
    if (strchr(str, '/')) { 
        sscanf_s(str, "%lld/%lld", &f.num, &f.den);
    }
    else if (strchr(str, '.')) { 
        double val = atof(str);
        long long precision = 1000000; 
        f.num = (long long)(val * precision);
        f.den = precision;
    }
    else { 
        f.num = atoll(str);
        f.den = 1;
    }
    return simplify(f);
}

void print_fraction(Fraction f) {
    f = simplify(f);
    if (f.den == 1) 
        printf("%lld\n", f.num);
    else 
        printf("%lld/%lld\n", f.num, f.den);
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.den + f2.num * f1.den, f1.den * f2.den };
    return simplify(res);
}

Fraction sub(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.den - f2.num * f1.den, f1.den * f2.den };
    return simplify(res);
}

Fraction mul(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.num, f1.den * f2.den };
    return simplify(res);
}

Fraction div_frac(Fraction f1, Fraction f2) {
    if (f2.num == 0) {
        fprintf(stderr, "Error: 0으로 나눌 수 없습니다.\n");
        exit(1);
    }
    Fraction res = { f1.num * f2.den, f1.den * f2.num };
    return simplify(res);
}