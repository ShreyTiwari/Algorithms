#include"header.h"

void main()
{
	char *buf; 				//long enough buffer for scanf'ing string of unknown length
	char **arr; 				//array of size n
	char *str;
	int n; 
	
	struct timespec start;
	struct timespec end;
	
	buf = (char*)malloc(pow(2,20)*sizeof(char));
	scanf(" %[^\n]", buf);

	
	str = (char*)malloc((1+strlen(buf))*sizeof(malloc));
	strcpy(str, buf);
	
	scanf("%d", &n);
	arr = (char **) malloc(n * sizeof(char*));
	
	for (int i = 0; i < n; ++i) 
	{
		scanf("  %[^\n]", buf);
		arr[i] = (char *) malloc ((1 + strlen(buf)) * sizeof(char));
		strcpy(arr[i], buf);
	}
	free(buf);	
	
	clock_gettime(CLOCK_REALTIME, &start);
	int *res = strmatch_patterns(str, arr, n);
	clock_gettime(CLOCK_REALTIME, &end); 
	
	
	for(int i = 0; i < n; i++)
	{
		printf("%d\n",  res[i]);
	}
	
	printf("%lf sec\n", time_elapsed(&start, &end));
	for (int i = 0; i < n; ++i)
	{
		free(arr[i]);
	}
	free(arr);
}








