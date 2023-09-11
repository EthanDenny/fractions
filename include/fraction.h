#ifndef INTEGER_FRACTION_TYPES
#define INTEGER_FRACTION_TYPES

typedef struct fraction {
    int n;
    int d;
} fraction_t;

fraction_t fraction_from_int(int n);
fraction_t fraction_from_float(float n);

#define compare_fractions(a, b) (((float) a.n / a.d) * b.d == b.n)

#define negate_fraction(f) f.n = -f.n
#define reciprocal_fraction(f) (f.n ^= f.d, f.d ^= f.n, f.n ^= f.d)

fraction_t add_fractions_by_components(int n1, int d1, int n2, int d2);
#define add_fractions(a, b) add_fractions_by_components(a.n, a.d, b.n, b.d)
#define subtract_fractions(a, b) add_fractions_by_components(a.n, a.d, -b.n, b.d)

fraction_t multiply_fractions_by_components(int n1, int d1, int n2, int d2);
#define multiply_fractions(a, b) multiply_fractions_by_components(a.n, a.d, b.n, b.d)
#define divide_fractions(a, b) multiply_fractions_by_components(a.n, a.d, b.d, b.n)

#define fraction_as_integer(f) (f.n / f.d)
#define fraction_as_float(f) ((float) f.n / f.d)
char* fraction_as_string(fraction_t f);

#endif
