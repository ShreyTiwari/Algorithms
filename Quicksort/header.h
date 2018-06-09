#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Data
{
	int id;
	int value;
};

//Quick Sort
//Use Quick Sort algorithm to sort the array an of records by their id.
void QuickSort(struct Data *a, int n);

//Hoare Partition
//Partitions the array on a pivot element and returns the index of the 
// pivot element in the partitioned array of records
int Partition(struct Data *a, int n);

double time_elapsed(struct timespec *start, struct timespec *end);
void display(struct Data *a, int n);
void swap(struct Data *x, struct Data *y);
