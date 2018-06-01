#include<stdio.h>
#include<stdlib.h>

void process(int array[], int n);
void display(int array[], int n);

void main()
{
    int n;

    printf("Welcome\n\nEnter the number of people in the circle: ");
    scanf("%d", &n);
    printf("\n");

    int *array = (int*)malloc(n*sizeof(int));

    for(int i = 1; i <= n; ++i)
        array[i-1] = i;

    process(array, n);
}

void process(int array[], int n)
{
    //display(array, n);
    //printf("\n");

    if(n == 3)
    { 
        printf("\nThe survivour is person number: %d\n\n", array[2]);
        return;
    }
    if(n == 2)
    {
        printf("\nThe survivour is person number: %d\n\n", array[0]);
        return;
    }

    if(n%2 == 1)
    {
        int k = 0;
        for(int i = 0; i < n; i = i+2)
            array[k++] = array[i];

        int temp = array[k-1];
        for(int i = k-1; i > 0; --i)
            array[i] = array[i-1];
        array[0] = temp;

        process(array, n/2 + 1);
    }
    else
    {
        int k = 0;
        for(int i = 0; i < n; i = i+2)
            array[k++] = array[i];

        process(array, n/2);
    }
}

void display(int array[], int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d  ", array[i]);
}