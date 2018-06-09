#include"header.h"

void main()
{
    struct timespec start, end;
    
    int n;
    scanf("%d", &n);

    int *array1 = (int*)malloc(n*sizeof(int));
    int *array2 = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &array1[i]);
        scanf("%d", &array2[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    DistributionCountingSorting(array1, n);
    clock_gettime(CLOCK_REALTIME, &end);
    //display(array1, n);
    printf("%lf sec\n", time_elapsed(&start, &end));

    clock_gettime(CLOCK_REALTIME, &start);
    MergeSort(array2, n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("%lf sec\n", time_elapsed(&start, &end));
}
