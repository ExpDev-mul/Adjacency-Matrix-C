#include <stdio.h> /* Standard input output */
#include <stdbool.h> /* Allows utilization of boolean types */

#define N 4
#define TRUE 1
#define FALSE 0
typedef int adjmat[N][N]; /* Create the type adjmat, as a N by N matrix of integers. */

bool path(adjmat mat, int u, int v); /* Returns whether there is a legal directed in the matrix from u to v */
void printMat(adjmat mat); /* Takes in a matrix and prints it out */
