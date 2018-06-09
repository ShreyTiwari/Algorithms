#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

void display(struct data *a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d %d\n", a[i].id, a[i].value);
}

void Merge(struct data *a, int n, int m)
{
    int i = 0;
    int j = m;
    int k = 0;

    struct data b[n];

    while((i < m) && (j < n))
    {
        if(a[i].value <= a[j].value)
        {
            b[k].value = a[i].value;
            b[k].id = a[i].id;
            ++i;
        }
        else
        {
            b[k].value = a[j].value;
            b[k].id = a[j].id;
            ++j;
        }
        ++k;
    }

    if(j == n)
    {
        while(i < m)
        {
            b[k].id = a[i].id;
            b[k].value = a[i].value;
            ++k;
            ++i;
        }
    }
    else
    {
       while(j < n)
        {
            b[k].id = a[j].id;
            b[k].value = a[j].value;
            ++k;
            ++j;
        } 
    }

    for(i = 0; i < n; ++i)
    {
        a[i].id = b[i].id;
        a[i].value = b[i].value;
    }
}

void MergeSort(struct data *a, int n)
{
    if(n <= 1) return;

    int m = (n/2);

    MergeSort(a, m);
    MergeSort(&(a[m]), n-m);

    Merge(a, n, m);
}

int BinarySearch(struct data *a, int n, int key)
{
    if(n < 1) return -1;

    int m = ((n-1)/2);

    if(a[m].value == key) return m;
    else if(key < a[m].value) return BinarySearch(a, m, key);
    else
    {
        int x = BinarySearch(&(a[m+1]), n-m-1, key);
        if(x < 0) return -1;
        else return m+1+x;
    }
}
