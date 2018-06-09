#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


struct data 
{
	int id;
	int value;
};

//Merge Sort
//Use Merge Sort algorithm to sort the array of length with respect to their values.
void MergeSort(struct data *a, int n);

//Merges two sorted arrays
void Merge(struct data *a, int n, int m);

//Binary Search
//Returns the index of one of the records of A which matches key_value with 'value'
int BinarySearch(struct data *a, int n, int key);

//Displays the sorted input
void display(struct data *a, int n);

double time_elapsed(struct timespec *start, struct timespec *end);