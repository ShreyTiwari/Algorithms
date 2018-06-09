//Header file for session9_heapsort.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Data 
{
	int id;
	int value;
};

//Heap Sort
//Use Heap Sort algorithm to sort the array an of records by their id.
void HeapSort(struct Data *A, int n);

//Construction of Heap from Bottom-up
void HeapBottomUp(struct Data *A, int n);

void heapify(struct Data *a, int n, int k);

double time_elapsed(struct timespec *start, struct timespec *end);

void display(struct Data *a, int n);