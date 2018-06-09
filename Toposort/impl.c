#include"header.h"
#include<stdio.h>
#include<stdlib.h>

int SmallestOutofOrderIndex(int *A, int n)
{
	for(int i = 1; i < n; ++i)
		if(A[i] < A[i-1]) return i;
	return -1;
}


int toposort(int **g, int n, int *topo_order)
{
	if(g==NULL || n==0) return 0;
	
	int flag = 0;
	int i, j = n, k, count, index = 0;
	int Loop_Counter = 0;    		
	int marked[n];	
	for(int i = 0; i < n; ++i) marked[i]  = 0;

	while(j > 0 && Loop_Counter <= n)
	{
	     for(i = 0; i < n; ++i )
	     {
	         if(marked[i] == 1) continue;
		 count = 0;
	         for(k = 0; k < n; ++k)
	         {
	             if(marked[k] == 1) continue;
	             if(g[k][i] == 0) ++count;
	         }
	
	         if(count == j)
	         { 
	             topo_order[index++] = i;
                     marked[i] = 1;
	             --j;
	         }
	     }
	     ++Loop_Counter;
	 } 
	
	 if(j > 0) return 0;
	 return 1;
}

/*
int BS1(int *a, int n, int key)
{
    if(n < 1) return -1;

    int m = ((n-1)/2);

    if(a[m] == key) return m;
    else if(key < a[m]) return BS1(a, m, key);
    else
    {
        int x = BS1(&(a[m+1]), n-m-1, key);
        if(x < 0) return -1;
        else return m+1+x;
    }
}


int BS2(int *a, int n, int key)
{
    if(n < 1) return -1;

    int m = ((n)/2);

    if(a[m] == key) return m;
    else if(key < a[m]) return BS2(a, m, key);
    else
    {
        int x = BS2(&(a[m+1]), n-m-1, key);
        if(x < 0) return -1;
        else return m+1+x;
    }
}
*/
int CountOccurrencesInSorted(int* a, int n, int key)
{
	if(n<1) return 0;

	int m = (n-1)/2;
	if(a[m] == key) return 1 + CountOccurrencesInSorted(a, m, key) + CountOccurrencesInSorted(&(a[m+1]), n-m-1, key);
	else if(key < a[m]) return CountOccurrencesInSorted(a, m, key);
	else return CountOccurrencesInSorted(&(a[m+1]), n-m-1, key);
}













