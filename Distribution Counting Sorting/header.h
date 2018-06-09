//Header file for session10_dcs.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double time_elapsed(struct timespec *start, struct timespec *end);

//Distribution Counting Sorting
//Returns the array sorted by the Distribution Counting Sorting algorithm.
//It finds the range of integers and then sorts.
void DistributionCountingSorting(int* A, int n);

//Merge Sort
//Returns the array sorted by the Merge Sort algorithm.
void MergeSort(int* A, int n);

void display(int *a, int n);