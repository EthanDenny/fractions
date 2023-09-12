# fractions

A library for C that uses two 4-byte integers to represent non-integer numbers as fractions.
This uses the same amount of memory as a 'double', but offers a *different type* of precision - namely, as long as integer overflow does not occur, fractions are guaranteed to perfectly represent the value expected, including values that can not be represented by a finite number of binary digits.
