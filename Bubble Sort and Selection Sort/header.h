#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio_ext.h>

struct Data
{
	int id;
	int value;
};

//Bubble Sort
//Use Bubble Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes. 
struct Data* BubbleSort(struct Data* a, int n, int k);

//Selection Sort
//Use Selection Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes. 
struct Data* SelectionSort(struct Data* a, int n, int p);

double time_elapsed(struct timespec *start, struct timespec *end);

void display(struct Data *a, int n);