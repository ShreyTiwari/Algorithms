#include"header.h"

void main()
{
    struct timespec start, end;

    char buff[1100000];
    scanf(" %[^\n]", buff);

    int len = strlen(buff);
    char *str = (char*)malloc(sizeof(char)*(len+1));
    strcpy(str, buff);

    int n;
    scanf("%d", &n);
    char **array = (char**)malloc(n*sizeof(char*));
    
    for(int i = 0; i < n; ++i)
    {
        scanf(" %[^\n]", buff);
        array[i] = (char*)malloc((1+strlen(buff))*sizeof(char));
        strcpy((array[i]), buff);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    int *res = horspools_strmatch_patterns(str, array, n);//function call;
    clock_gettime(CLOCK_REALTIME, &end);
    //display(res, n);
    printf("%lf sec\n", time_elapsed(&start, &end));

    clock_gettime(CLOCK_REALTIME, &start);
    int *res1 = strmatch_patterns(str, array, n);//function call;
    clock_gettime(CLOCK_REALTIME, &end);
    printf("%lf sec\n", time_elapsed(&start, &end));

    free(res);
    for(int i = 0; i < n; ++i)
        free(array[i]);
    free(array);
}
