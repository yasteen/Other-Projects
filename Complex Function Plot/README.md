# Complex-function-colour-plot
Plots a function f: C -> C using colour.

Java version: 1.7

To use:
The program requires separation into imaginary and real parts. For the function
g(z) where z = x + iy, we have: f(x, y) = (u, v) where the output is u + iv

So u is the real part of the output, and v is the imaginary part.

To specify the function that is to be plotted, in Draw.java, change the values of u and v to be functions of x and y

Compile:

    javac Main.java
    
Run:

    java Main
