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

void QuickSort(struct Data *a, int n)
{
    if(n <= 1) return;

    int s = Partition(a, n);

    QuickSort(a, s);
    QuickSort(&(a[s+1]), n-s-1);
}

int Partition(struct Data *a, int n)
{
    int p = a[0].id;
    int i = 1;
    int j = n-1;

    while(i <= j)
    {
        while(i <= j && a[i].id < p) ++i;
        while(i <= j && a[j].id > p) --j;

        if(i < j)
        {
            swap(&a[i], &a[j]);
            ++i;
            --j;
        }
    }

    swap(&a[0], &a[j]);

    return j;
}

void swap(struct Data *x, struct Data *y)
{
    int temp;

    temp = x->id;
    x->id = y->id;
    y->id = temp;

    temp = x->value;
    x->value = y->value;
    y->value = temp;
}
