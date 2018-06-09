#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

double time_elapsed(struct timespec *start, struct timespec *end);


int main()
{

	struct timespec start;
	struct timespec end;

	char *buffer=(char *)malloc(sizeof(char)*(pow(2,20)+1));
	scanf(" %[^\n]",buffer);
	int n=strlen(buffer);
	char *text=(char *)malloc(sizeof(char)*(n+1));
	strcpy(text,buffer);
	int t;
	int m;
	scanf("%d",&t);
	char **patterns=(char **)malloc(sizeof(char *)*(t));
	for(int i=0;i<t;i++)
	{
		scanf(" %[^\n]",buffer);
		m=strlen(buffer);
		patterns[i]=(char *)malloc(sizeof(char)*(m+1));
		strcpy(patterns[i],buffer);
	}

	clock_gettime(CLOCK_REALTIME, &start); //start timestamp
	int * result=horspools_strmatch_patterns(text, patterns, t);
	clock_gettime(CLOCK_REALTIME, &end); //end timestamp
	
	free(buffer);
	free(text);
	free(patterns);
	for(int i=0;i<t;i++)
	{
		printf("%d\n",result[i]);
	}
	printf("%lf sec\n", time_elapsed(&start, &end));

}
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
