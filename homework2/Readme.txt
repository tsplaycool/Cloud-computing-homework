To compile the code :mpicc -o homework2 -fopenmp homework2.c -lm

TO execute the program :mpiexec -np N ./homework2 VECTORSIZE
         N: the total number of the processes
VECTORSIZE: the size of the vector (don't too large, if large enough will result to the Memory Overflow)

example:  mpiexec -np 4 ./homework2 4
 result:
	Random vector is:
 	 3  6  8  3
	The geometric mean is 4.559014

I use the "mpiexec" it also can be replaced by "mpirun"
