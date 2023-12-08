### [Bit numbering](https://en.wikipedia.org/wiki/Bit_numbering)
#### [Most significant bit (MSb)](https://en.wikipedia.org/wiki/Bit_numbering#Most_significant_bit)
a.k.a. the *high-order bit* or *left-most bit*. The highest-order place of the binary integer.

#### Least significant bit (MSb)
a.k.a. *low-order bit* or *right-most bit*, due to convention in positional notation of writing less significant digits further to the right.

[Two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)
- The most common method of representing signed (positive, negative, zero) integers on computers, and more generally, [fixed point binary](https://en.wikipedia.org/wiki/Fixed-point_arithmetic) values.
- Uses the binary digit with the greatest place value (MSb, see above) to indicate if positive (1) or negative (0).
- General method: take the absolute value of the number, invert all bits, add 1 to the entire inverted number, ignoring any overflow (n.b.: accounting for overflow will produce the wrong value).

