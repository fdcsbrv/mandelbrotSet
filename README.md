# The Mandelbrot set (mandelbrotSet)
The Mandelbrot set is the set of values of c in the complex plane,
for which the orbit of the critical point $z = 0$ under iteration of the quadratic map.

$z_{n + 1} = z_{n}^{2} + c$ 

remains bounded.
Thus, a complex number c is a member of the Mandelbrot set if, when starting with 
$z_{0} = 0$ and applying the iteration repeatedly, the absolute value of the $n$-th
iteration stays bounded $\forall n > 0$.

## User set parameters

## Results
The code produces a file whose results are three columns $(x, y, \text{magnitude})$.
A plotting program is needed to display the results. In gnuplot the following command plots the output:
```
set view map
splot mandelbrot_nIterations_<value>_nX_<value>_nY_<value>.dat with p ps 3 pt 5 palette
```