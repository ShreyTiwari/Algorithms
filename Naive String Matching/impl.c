#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
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


















