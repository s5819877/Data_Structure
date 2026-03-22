#include "my_math.h"
#include <stdlib.h>

long long gcd(long long a, long long b) {
    if (a == 0 && b == 0) 
        return -1; 

    a = llabs(a); 
    b = llabs(b);

    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) {
    long long g = gcd(a, b);
    if (g == -1) 
        return -1; 
    if (a == 0 || b == 0) 
        return 0; 

    return llabs((a / g) * b);
}