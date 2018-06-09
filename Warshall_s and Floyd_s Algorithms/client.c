#include"header.h"

void main()
{
    struct timespec start1, start2, end1, end2;
    int n1, n2;

    scanf("%d", &n1);
    int **array1 = (int**)malloc(n1*sizeof(int*));
    for(int i = 0; i < n1; ++i)
        array1[i] = (int*)malloc(n1*sizeof(int));

    for(int i = 0; i < n1; ++i)
        for(int j = 0; j < n1; ++j)
            scanf("%d", &array1[i][j]);

    //scanf("%d", &n2);
    scanf("%d", &n2);
    int **array2 = (int**)malloc(n2*sizeof(int*));
    for(int i = 0; i < n2; ++i)
        array2[i] = (int*)malloc(n2*sizeof(int));

    for(int i = 0; i < n2; ++i)
        for(int j = 0; j < n2; ++j)
            scanf("%d", &array2[i][j]);

    clock_gettime(CLOCK_REALTIME, &start1);
    transitive_closure_warshalls(array1, n1);//function call;
    clock_gettime(CLOCK_REALTIME, &end1);
    
    clock_gettime(CLOCK_REALTIME, &start2);
    all_pairs_shortest_path_distances_floyds(array2, n2);//function call;
    clock_gettime(CLOCK_REALTIME, &end2);

    display(array1, n1);
    printf("\n");
    display(array2, n2);
    printf("%lf sec\n", time_elapsed(&start1, &end1));
    printf("%lf sec\n", time_elapsed(&start2, &end2));

    //printf("%d %d", n1, n2);

    for(int k = 0; k < n1; ++k)
        free(array1[k]);

    for(int k = 0; k < n2; ++k)
        free(array2[k]);

    free(array1);
    free(array2);
}