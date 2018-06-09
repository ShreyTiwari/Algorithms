//Header file for session12_WarshallsFloyds.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double time_elapsed(struct timespec *start, struct timespec *end);
void display(int **g, int n);

void transitive_closure_warshalls(int **g, int n);
void all_pairs_shortest_path_distances_floyds(int **g, int n);
