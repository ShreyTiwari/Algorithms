#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int** matrix, int n);

int get_next_permutation(int *permutation, int n);
int cal_dist(int *permutation, int n, int **matrix);

double time_elapsed(struct timespec *start, struct timespec *end);