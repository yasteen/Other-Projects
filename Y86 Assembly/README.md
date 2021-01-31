# Assembly Projects
Repository of assembly projects

### determinant.ys
This program was written for a Y86 ISA without mulq (multiplication) and divq (division).
In place of mulq, a "multiply" function was created. The running time for this multiplication function
is O(min(n, m)) for multiply(n, m). This can be done in logarithmic time, but it may not be as practical
for multiplying smaller numbers.

This determinant calculator calls a recursive function "det", which loops through the top row of the n x n matrix and multiplies
each entry with the corresponding (n-1) x (n-1) sub-matrix (alternating sign each time).
