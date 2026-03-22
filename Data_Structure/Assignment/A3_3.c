#include <stdio.h>
#include <stdlib.h>
#include "my_fraction.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s width height\n", argv[0]);
        return 1;
    }

    Fraction width = create_from_string(argv[1]);
    Fraction height = create_from_string(argv[2]);

    if (width.num <= 0 || height.num <= 0) {
        fprintf(stderr, "Error: 가로와 세로는 양수여야 합니다.\n");
        return 1;
    }

    Fraction sum = add(width, height);
    Fraction two = (Fraction){ 2, 1 };
    Fraction perimeter = mul(sum, two);

    Fraction area = mul(width, height);

    printf("Perimeter: ");
    print_fraction(perimeter);
    printf(", Area: ");
    print_fraction(area);

    return 0;
}