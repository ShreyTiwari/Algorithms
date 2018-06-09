#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}

int tsp(int** matrix, int n)
{
	int permutation[n];
	int x, min;

	for(int i = 0; i < n; i++) 
		permutation[i] = i;

	min = cal_dist(permutation, n, matrix);
	x = get_next_permutation(permutation, n);
	do 
	{
		if(permutation[0] != 0) break; 
		x = cal_dist(permutation, n, matrix);
		if(x < min)
			min = x;		
	} while (get_next_permutation(permutation, n));

	return min;
}

int cal_dist(int *permutation, int n, int **matrix)
{
	int i,sum = 0;

	for(i = 0; i < (n-1); ++i)
		sum = sum + matrix[permutation[i]][permutation[i+1]];

	sum = sum + matrix[permutation[i]][permutation[0]];

	return sum;
}