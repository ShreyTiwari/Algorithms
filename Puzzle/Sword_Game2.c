/*
Note1: This program is written after observing Sword_Game1 prog output.
Note2: All functions are written explicitly even if there preexisting versions.
*/

#include<stdio.h>
#include<math.h>

void process(int n);
int floor_log(int n);
int power(int n);

void main()
{
    int n;

    printf("Welcome\n\nEnter the number of people in the circle: ");
    scanf("%d", &n);
    printf("\n");

    process(n);
}

void process(int n)
{
    int temp = n - power(floor_log(n));
    printf("The survivour is person number: %d\n", (2*temp + 1));
}

int floor_log(int n)
{
    int count = 0;
    while(n > 1)
    {
        n = n/2;
        ++count;
    }
    //printf("Floor_log: %d\n", count);
    return count;
}

int power(int n)
{
    int ans = 1;
    for(int i = 0; i < n; ++i)
        ans = ans*2;
    return ans;
}