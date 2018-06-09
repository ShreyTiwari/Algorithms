#include"header.h"

void main()
{
    struct timespec start, start1, end1, end;

    int n, key, pos;
    struct data *array;

    scanf("%d", &n);

    array = (struct data*)malloc(n*sizeof(struct data));

    for(int i = 0; i < n; ++i)
       scanf("%d %d", &(array[i].id), &(array[i].value));
    
    scanf("%d", &key);

    clock_gettime(CLOCK_REALTIME, &start);
    MergeSort(array, n);
    clock_gettime(CLOCK_REALTIME, &end);

    clock_gettime(CLOCK_REALTIME, &start1);
    pos = BinarySearch(array, n, key);
    clock_gettime(CLOCK_REALTIME, &end1);
	

    display(array, n);

    if(pos == -10)
        printf("NOT FOUND\n");
    else
        printf("%d %d %d\n", pos, array[pos].id, array[pos].value);

    printf("%lf sec\n", time_elapsed(&start, &end));
    printf("%lf sec\n", time_elapsed(&start1, &end1));

    free(array);
}
