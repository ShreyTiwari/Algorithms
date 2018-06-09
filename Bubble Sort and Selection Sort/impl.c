#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

void display(struct Data *a, int n)
{
	for(int i = 0; i < n; ++i)
		printf("%d %d\n", a[i].id, a[i].value);
}

struct Data* BubbleSort(struct Data *a, int n, int k)
{
	int noSwap, temp;

	for(int i = 0; i < n-1; ++i )
	{
		noSwap = 1;

		if(k == i)
		{
			display(a, n);
		}

		for(int j = 0; j < n-1-i; ++j)
		{
			if(a[j].value > a[j+1].value)
			{
				temp = a[j].value;
				a[j].value = a[j+1].value;
				a[j+1].value = temp;

				temp = a[j].id;
				a[j].id = a[j+1].id;
				a[j+1].id = temp;

				noSwap = 0;
			}
		}

		if(noSwap == 1) 
		{
			break;
		}
	}

	display(a, n);

	if(k >= n)
		display(a, n);

	return a;
}


struct Data* SelectionSort(struct Data *a, int n, int k)
{
	int min, temp;

	for(int i = 0; i < n-1; ++i)
	{
		min = i;

		if(k == i)
			display(a, n);

		for(int j = (i+1); j < n; ++j)
		{
			if(a[j].value < a[min].value)
			{
				min  =j;
			}
		}

		temp = a[i].value;
		a[i].value = a[min].value;
		a[min].value = temp;

		temp = a[i].id;
		a[i].id = a[min].id;
		a[min].id = temp;

	}

	display(a, n);

	if(k >= n)
		display(a, n);

	return a;
}