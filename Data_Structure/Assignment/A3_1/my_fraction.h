#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct {
    long long num; 
    long long den; 
} Fraction;

Fraction create_from_string(char* str);
Fraction simplify(Fraction f);
void print_fraction(Fraction f);

Fraction add(Fraction f1, Fraction f2);
Fraction sub(Fraction f1, Fraction f2);
Fraction mul(Fraction f1, Fraction f2);
Fraction div_frac(Fraction f1, Fraction f2);

#endif