#include"header.h"

void main()
{
    struct timespec start, end;

    struct Record *A, *B, *C, *D, *E;
    int n;
    long int x;

    scanf("%d", &n);

    A = (struct Record*)malloc(n*sizeof(struct Record));
    B = (struct Record*)malloc(n*sizeof(struct Record));
    C = (struct Record*)malloc(n*sizeof(struct Record));
    D = (struct Record*)malloc(n*sizeof(struct Record));
    E = (struct Record*)malloc(n*sizeof(struct Record));

    for(int i = 0; i < n; ++i)
    {
        scanf("%ld %d", &(A[i].serialnumber), &(A[i].score));
        B[i].serialnumber = A[i].serialnumber;
        C[i].serialnumber = A[i].serialnumber;
        D[i].serialnumber = A[i].serialnumber;
        E[i].serialnumber = A[i].serialnumber;

        B[i].score = A[i].score;
        C[i].score = A[i].score;
        D[i].score = A[i].score;
        E[i].score = A[i].score;
    }

    clock_gettime(CLOCK_REALTIME, &start);
    x = InsertionSort(A, n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Insertion Sort: %ld %lf \n", x, time_elapsed(&start, &end));

    clock_gettime(CLOCK_REALTIME, &start);
    x = BubbleSort(B, n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Bubble Sort: %ld %lf \n", x, time_elapsed(&start, &end));

    clock_gettime(CLOCK_REALTIME, &start);
    x = SelectionSort(C, n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Selection Sort: %ld %lf \n", x, time_elapsed(&start, &end));

    clock_gettime(CLOCK_REALTIME, &start);
    x = MergeSort(D, n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Merge Sort: %ld %lf \n", x, time_elapsed(&start, &end));

    clock_gettime(CLOCK_REALTIME, &start);
    x = QuickSort(E, n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Quick Sort: %ld %lf \n", x, time_elapsed(&start, &end));

    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
}