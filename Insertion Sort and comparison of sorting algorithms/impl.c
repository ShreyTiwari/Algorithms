#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end)
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}






//Quick Sort

void swap(struct Record *x, struct Record *y)
{
    long int temp;

    temp = x->serialnumber;
    x->serialnumber = y->serialnumber;
    y->serialnumber = temp;

    temp = x->score;
    x->score = y->score;
    y->score = temp;
}

int Partition(struct Record *a, int n, long int *x)
{
    int e = a[0].serialnumber;
    int f = a[n-1].serialnumber;
    int g = a[(n)/2].serialnumber;

    if(f > e && f < g || f > g && f < e)
        swap(&a[0], &a[n-1]);

    if(g > e && g < f || g > f && g < e)
        swap(&a[0], &a[n/2]);

    long int p = a[0].serialnumber;
    int i = 1;
    int j = n-1;

    while(i <= j)
    {
        while(i <= j && ++(*x) && a[i].serialnumber <= p) ++i;
        while(i <= j && ++(*x) && a[j].serialnumber > p) --j;

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

long int QuickSort(struct Record *A, int n)
{
    long int count = 0;

    if(n <= 1) return 0;

    int s = Partition(A, n, &count);

    long int x = QuickSort(A, s);
    long int y = QuickSort(&(A[s+1]), n-s-1);

    return count + x + y;
}







//Merge Sort

long int Merge(struct Record *a, int n, int m)
{
    long int count = 0;

    int i = 0;
    int j = m;
    int k = 0;

    struct Record b[n];

    while((i < m) && (j < n))
    {
        if(a[i].serialnumber <= a[j].serialnumber)
        {
            b[k].serialnumber = a[i].serialnumber;
            b[k].score = a[i].score;
            ++i;
        }
        else
        {
            b[k].serialnumber = a[j].serialnumber;
            b[k].score = a[j].score;
            ++j;
        }
        ++k;
        ++count;
    }

    if(j == n)
    {
        while(i < m)
        {
            b[k].score = a[i].score;
            b[k].serialnumber = a[i].serialnumber;
            ++k;
            ++i;
        }
    }
    else
    {
       while(j < n)
        {
            b[k].score = a[j].score;
            b[k].serialnumber = a[j].serialnumber;
            ++k;
            ++j;
        } 
    }

    for(i = 0; i < n; ++i)
    {
        a[i].score = b[i].score;
        a[i].serialnumber = b[i].serialnumber;
    }

    return count;
}

long int MergeSort(struct Record *A, int n)
{
    long int count = 0;

    if(n <= 1) return 0;

    int m = (n/2);

    long int x = MergeSort(A, m);
    long int y = MergeSort(&(A[m]), n-m);

    count = Merge(A, n, m);

    return count + x + y;
}







//Bubble Sort

long int BubbleSort(struct Record *A, int n)
{
	int noSwap, temp;
    long int count = 0;

	for(int i = 0; i < n-1; ++i)
	{
		noSwap = 1;

		for(int j = 0; j < n-1-i; ++j)
		{
			if(++count && (A[j].serialnumber > A[j+1].serialnumber))
			{
				temp = A[j].serialnumber;
				A[j].serialnumber = A[j+1].serialnumber;
				A[j+1].serialnumber = temp;

				temp = A[j].score;
				A[j].score = A[j+1].score;
				A[j+1].score = temp;

				noSwap = 0;
                
			}
		}

		if(noSwap == 1) 
		{
			break;
		}
	}

	return count;
}







//Selection Sort

long int SelectionSort(struct Record *A, int n)
{
	int min, temp;
    long int count = n;

	for(int i = 0; i < n-1; ++i)
	{
		min = i;

		for(int j = (i+1); j < n; ++j)
		{
			if((A[j].serialnumber < A[min].serialnumber))
			{
				min  = j;
			}
		}

		temp = A[i].serialnumber;
		A[i].serialnumber = A[min].serialnumber;
		A[min].serialnumber = temp;

		temp = A[i].score;
		A[i].score = A[min].score;
		A[min].score = temp;

	}

	return(count*(count-1)/2);
}








//Insertion Sort
long int InsertionSort(struct Record *A, int n)
{
    long int temp1;
    int temp2;
    int j;
    long int count = 0;

    for(int i = 1; i < n; ++i)
    {
        temp1 = A[i].serialnumber;
        temp2 = A[i].score;
        
        j = i-1;
        while(j >= 0 && ++count && A[j].serialnumber > temp1)
        {
            A[j+1].serialnumber = A[j].serialnumber;
            A[j+1].score = A[j].score;

            --j;
        }

        A[j+1].serialnumber = temp1;
        A[j+1].score = temp2;

    }

    return count;
}