#include"header.h"

void main()
{
    struct timespec start, end;
    
    int n;
    scanf("%d", &n);

    struct Data *array = (struct Data*)malloc((n+1)*sizeof(struct Data));

    for(int i = 1; i <= n; ++i)
        scanf("%d %d", &(array[i].id), &(array[i].value));

    clock_gettime(CLOCK_REALTIME, &start);
    HeapSort(array, n);
    clock_gettime(CLOCK_REALTIME, &end);

    display(array, n);
    printf("%lf sec\n", time_elapsed(&start, &end));

    free(array);
}
