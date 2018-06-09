#include"header.h"
#define inf 1000000
#define min(x, y) (x < y)? x: y; 

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t  += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

void display(int **g, int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}

void transitive_closure_warshalls(int **g, int n)
{
	for(int k = 0; k < n; ++k)
        	for(int i = 0; i < n; ++i)
            		for(int j = 0; j < n; ++j)
                		g[i][j] = (g[i][j] || ( g[i][k] && g[k][j]));
}

void all_pairs_shortest_path_distances_floyds(int **g, int n)
{
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], (g[i][k] + g[k][j]));
}
