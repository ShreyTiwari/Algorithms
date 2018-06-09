#include"header.h"

void main()
{
	struct Data *a, *b;
    int n, k;

    struct timespec start1, start2;
	struct timespec end1, end2;

    scanf("%d", &n);

    a = (struct Data*)malloc(n*sizeof(struct Data));
    b = (struct Data*)malloc(n*sizeof(struct Data));

    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &(a[i].id), &(a[i].value));
        b[i].id = a[i].id;
        b[i].value = a[i].value;
    }

    scanf("%d", &k);

    clock_gettime(CLOCK_REALTIME, &start1);
	a = BubbleSort(a, n, k);//bubble sort
	clock_gettime(CLOCK_REALTIME, &end1); 

    clock_gettime(CLOCK_REALTIME, &start2);
	b = SelectionSort(b, n, k);//selection sort
	clock_gettime(CLOCK_REALTIME, &end2); 
    

    printf("%lf sec\n", time_elapsed(&start1, &end1));//bubble sort time
    printf("%lf sec\n", time_elapsed(&start2, &end2));//selection sort time

    free(a);
}