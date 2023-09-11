#include <stdlib.h>
#include <stdio.h>
#include "../include/fraction.h"

fraction_t add_fractions_by_components(int n1, int d1, int n2, int d2) {
    fraction_t result;

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

fraction_t multiply_fractions_by_components(int n1, int d1, int n2, int d2) {
    fraction_t result;

    result.n = n1 * n2;
    result.d = d1 * d2;

    while (result.n % 2 == 0 && result.d % 2 == 0) {
        result.n >>= 1;
        result.d >>= 1;
    }

    return result;
}

fraction_t fraction_from_int(int n) {
    fraction_t f = {n, 1};
    return f;
}

fraction_t fraction_from_float(float n) {
    int d = 1;

    while ((int) n != n) {
        n *= 2;
        d *= 2;
    }

    fraction_t f = {n, d};

    return f;
}

char* fraction_as_string(fraction_t f) {
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
