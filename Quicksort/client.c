#include"header.h"

void main()
{
    struct timespec start, end;

    int n;
    struct Data *array;

    scanf("%d", &n);

    array = (struct Data*)malloc(n*sizeof(struct Data));

    for(int i = 0; i < n; ++i)
    {
       scanf("%d %d", &(array[i].id), &(array[i].value));
    }


    clock_gettime(CLOCK_REALTIME, &start);
    QuickSort(array, n);
    clock_gettime(CLOCK_REALTIME, &end);

    display(array, n);

    printf("%lf sec\n", time_elapsed(&start, &end));

}
