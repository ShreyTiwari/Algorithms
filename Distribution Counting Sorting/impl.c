#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

void display(int *a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d\n", a[i]);
}

void Merge(int *a, int n, int m)
{
    int i = 0;
    int j = m;
    int k = 0;

    int b[n];

    while((i < m) && (j < n))
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            ++i;
        }
        else
        {
            b[k] = a[j];
            ++j;
        }
        ++k;
    }

    if(j == n)
    {
        while(i < m)
        {
            b[k] = a[i];
            ++k;
            ++i;
        }
    }
    else
    {
       while(j < n)
        {
            b[k] = a[j];
            ++k;
            ++j;
        } 
    }

    for(i = 0; i < n; ++i)
    {
        a[i] = b[i];
    }
}

void MergeSort(int *a, int n)
{
    if(n <= 1) return;

    int m = (n/2);

    MergeSort(a, m);
    MergeSort(&(a[m]), n-m);

    Merge(a, n, m);
}

void DistributionCountingSorting(int* A, int n)
{
	int min=A[0],max=A[0];
	for(int i=0;i<n;i++)
	{
		if(min>A[i]) min=A[i];
		if(max<A[i]) max=A[i];
	}

	int size=max-min+1;
	long int *D=(long int*)calloc(size, sizeof(long int));
	for(int i=0;i<n;i++)D[A[i]-min]++;
	for(int j=1;j<size;j++)
		D[j] = D[j-1] + D[j];
	int j;
	int *s = (int*)malloc(n*sizeof(int));
	for(int i = n-1; i >= 0; --i)
	{
		j = A[i]-min;
		s[D[j]-1] = A[i];
		--D[j];
	}
	free(D);
	
	for(int i = 0; i < n; ++i) A[i] = s[i];

	free(s);
}