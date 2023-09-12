#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../include/fraction.h"

int main() {
    Fraction a = fraction_from_int(2);

    assert(a.n == 2);
    assert(a.d == 1);

    Fraction b = fraction_from_float(10.5);

    assert(!compare_fractions(a, b));
    assert(compare_fractions(a, a));
    assert(compare_fractions(b, b));

    assert(b.n == 21);

    negate_fraction(a);

    assert(a.n == -2);
    assert(a.d == 1);

    reciprocal_fraction(b);

    assert(b.n == 2);
    assert(b.d == 21);

    assert(add_fractions(a, b).n == -40);
    assert(add_fractions(a, b).d == 21);

    assert(subtract_fractions(a, b).n == -44);
    assert(subtract_fractions(a, b).d == 21);

    assert(multiply_fractions(a, b).n == -4);
    assert(multiply_fractions(a, b).d == 21);

    assert(divide_fractions(a, b).n == -21);
    assert(divide_fractions(a, b).d == 1);

    assert(fraction_as_integer(a) == -2);
    assert(fraction_as_float(b) == 0.095238097012042999267578125);
    assert(strcmp(fraction_as_string(b), "2/21") == 0);
    
    printf("All tests passed.\n");
}
