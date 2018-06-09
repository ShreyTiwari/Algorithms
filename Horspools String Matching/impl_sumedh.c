#include "header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t  += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

void display(int *array, int n)
{
	for(int i = 0; i < n; ++i)
		printf("%d\n", array[i]);
}

int * ShiftTable(char *pattern, int m);

int *horspools_strmatch_patterns(char *text, char **patterns, int t)
{

	int *result=(int *)malloc(sizeof(int)*t);
	for(int i=0;i<t;i++)
	{
		result[i]=horspools_strmatch_pattern(text, patterns[i]);
	}
	return result;
}

int horspools_strmatch_pattern(char *text, char *pattern)
{
	int m=strlen(pattern);
	int n=strlen(text);
	int *table=ShiftTable(pattern,m);
	int i=m-1;
	while(i<n)
	{
		int j=0;
		while(j<m && text[i-j]==pattern[m-1-j])
		{
			j++;
		}
		if(j==m)
		{

			return i-j+1;
		}
		i = i + table[text[i]];
	}
	return -1;
}
 int * ShiftTable(char *pattern, int m)
 {
 	int *table=(int *)malloc(sizeof(int)*256);
 	for(int i=0;i<256;i++)
 		table[i]=m;
 	for(int i=0;i<m-1;i++)
 	{
 		table[pattern[i]]=m-(i+1);
 	}
 	return table;
 }
