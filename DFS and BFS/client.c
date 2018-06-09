#include"header.h"

void main()
{
    struct timespec start, end;
    double timetaken = 0;
    int k,n, comp;
    char c;

    scanf("%d", &k);
    scanf("%c", &c);

    for(int i = 0; i < k; ++i)
    {
        scanf("%d", &n);
        int **g = (int**)malloc(n*sizeof(int*));
        for(int j = 0; j < n; ++j)
            g[j] = (int*)malloc(n*sizeof(int));

        for(int a = 0; a < n; ++a)
        {
            for(int b = 0; b < n; ++b)
                scanf("%d", &g[a][b]);
        }

        clock_gettime(CLOCK_REALTIME, &start);
        comp = BFS_main(g, n);
        clock_gettime(CLOCK_REALTIME, &end);
        timetaken += time_elapsed(&start, &end);

        scanf("%c", &c);

        printf("%d\n", comp);
    }

    printf("%lf sec\n", timetaken);
}