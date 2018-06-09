#include"header.h"


void main()
{
    struct timespec start, end;

    int n;
    int **matrix;

    scanf("%d", &n);

    matrix = (int**)malloc(n*sizeof(int*));

    for(int i = 0; i < n; ++i)
        matrix[i] = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            scanf("%d", &matrix[i][j]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    int ans = tsp(matrix, n);
	clock_gettime(CLOCK_REALTIME, &end); 
    

    printf("%d\n", ans);
    printf("%lf sec\n", time_elapsed(&start, &end));

    for(int i = 0; i < n; ++i)
        free(matrix[i]);
    free(matrix);
}