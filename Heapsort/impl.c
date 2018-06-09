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
    for(int i = 1; i <= n; ++i)
        printf("%d %d\n", a[i].id, a[i].value);
}

void swap(struct Data *a, struct Data *b)
{
    int temp;

    temp = a->id;
    a->id = b->id;
    b->id = temp;

    temp = a->value;
    a->value = b->value;
    b->value = temp;
	
}

void HeapSort(struct Data *A, int n)
{
    HeapBottomUp(A, n);

    for(int i = n; i >= 2; --i)
    {
        swap(&A[1], &A[i]);
        heapify(A, i-1, 1);
    }
}

void HeapBottomUp(struct Data *A, int n)
{
    if(n <= 1) return;

    for(int i = n/2; i >= 1; --i)
        heapify(A, n, i);
}

void heapify(struct Data *a, int n, int k)
{
    if(2*k > n) return;

    int j = 2*k;
    if(j+1 <= n && a[j+1].id > a[j].id) ++j;
    if(a[j].id > a[k].id) swap(&a[j], &a[k]);

    heapify(a, n, j);
}
