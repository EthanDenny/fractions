#include <stdlib.h>
#include <stdio.h>
#include "../include/fraction.h"

Fraction create_fraction(int n, int d) {
    Fraction f = {n, d};
    return f;
}

Fraction fraction_from_float(float n) {
    int d = 1;

    while ((int) n != n) {
        n *= 2;
        d *= 2;
    }

    return create_fraction(n, d);
}

Fraction fraction_from_double(double n) {
    int d = 1;

    while ((int) n != n) {
        n *= 2;
        d *= 2;
    }

    return create_fraction(n, d);
}

Fraction add_fractions_by_components(int n1, int d1, int n2, int d2) {
    Fraction result;

    if (d1 == d2) {
        result.n = n1 + n2;
        result.d = d1;
    } else {
        result.n = n1 * d2 + n2 * d1;
        result.d = d1 * d2;

        while (result.n % 2 == 0 && result.d % 2 == 0) {
            result.n >>= 1;
            result.d >>= 1;
        }
    }

    return result;
}

Fraction multiply_fractions_by_components(int n1, int d1, int n2, int d2) {
    Fraction result;

    result.n = n1 * n2;
    result.d = d1 * d2;

    while (result.n % 2 == 0 && result.d % 2 == 0) {
        result.n >>= 1;
        result.d >>= 1;
    }

    return result;
}

char* fraction_as_string(Fraction f) {
    char* str;

    if (f.d == 1) {
        int length = snprintf(NULL, 0, "%d", f.n);
        str = malloc(length + 1);
        snprintf(str, length + 1, "%d", f.n);
        return str;
    } else {
        int length = snprintf(NULL, 0, "%d/%d", f.n, f.d);
        str = malloc(length + 1);
        snprintf(str, length + 1, "%d/%d", f.n, f.d);
    }

    return str;
}
