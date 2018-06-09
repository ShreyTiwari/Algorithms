#include"header.h"

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

int* horspools_strmatch_patterns(char *text, char **patterns, int t)
{	
	int *res = (int*)malloc(t*sizeof(int)); 
	for(int i = 0; i < t; ++i)
		res[i] = horspools_strmatch_pattern(text, patterns[i]);

	return res;
}

int* shifttable(char *pattern)
{
	int *a = (int*)malloc(256*sizeof(int));

	int len = strlen(pattern);
	for(int j = 0; j < 256; ++j) a[j] = len;
	for(int j = 0; j < len-1; ++j) a[pattern[j]] = len -1 -j;

	return a;
}

int horspools_strmatch_pattern(char *text, char *pattern)
{
	int *table = shifttable(pattern);

	int m = strlen(pattern);	
	int n = strlen(text);

	int j, i = m -1;
	while(i < n)
	{
		j  = 0;
		while(j < m && text[i-j] == pattern[m-1-j])
			++j;
		if(j == m) 
		{
			free(table);
			return i-m+1;
		}
		i = i + table[(unsigned char)text[i]];
	}
	free(table);
	return -1;
}

/*
int horspools_strmatch_pattern(char *text, char *pattern)
{
	int m=strlen(pattern);
	int n=strlen(text);
	int *table=shifttable(pattern);
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
}*/


int strmatch_pattern(char *str, char *pattern)
{
	int x = strlen(str);
	int y = strlen(pattern);
	int flag;
	
	for(int i = 0; i < x-y+1; i++)
	{
		int j= 0;
		
		while(j<y && pattern[j] == str[i+j])
			j++;
		
		if(j == y)
			return i;
	}
	
	return -1;
}

int *strmatch_patterns(char *str, char **patterns, int t)
{
	int *ResArray = (int*)malloc(t * sizeof(int));
	
	for(int i = 0; i < t; ++i)
	{
		ResArray[i] = strmatch_pattern(str, patterns[i]);
	}
	
	return ResArray;
}


