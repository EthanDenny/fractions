#ifndef INTEGER_FRACTION_TYPES
#define INTEGER_FRACTION_TYPES

typedef struct fraction {
    int n;
    int d;
} Fraction;

Fraction create_fraction(int n, int d);

#define fraction_from_int(n) create_fraction(n, 1);
Fraction fraction_from_float(float n);
Fraction fraction_from_double(double n);

#define compare_fractions(a, b) (((double) a.n / a.d) * b.d == b.n)

#define negate_fraction(f) f.n = -f.n
#define reciprocal_fraction(f) (f.n ^= f.d, f.d ^= f.n, f.n ^= f.d)

Fraction add_fractions_by_components(int n1, int d1, int n2, int d2);
#define add_fractions(a, b) add_fractions_by_components(a.n, a.d, b.n, b.d)
#define subtract_fractions(a, b) add_fractions_by_components(a.n, a.d, -b.n, b.d)

Fraction multiply_fractions_by_components(int n1, int d1, int n2, int d2);
#define multiply_fractions(a, b) multiply_fractions_by_components(a.n, a.d, b.n, b.d)
#define divide_fractions(a, b) multiply_fractions_by_components(a.n, a.d, b.d, b.n)

#define fraction_as_integer(f) (f.n / f.d)
#define fraction_as_float(f) ((float) f.n / f.d)
#define fraction_as_double(f) ((double) f.n / f.d)
char* fraction_as_string(Fraction f);

#endif
