#include"header.h"

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

int DFS_main(int **g, int n)
{
    int *vertices = (int*)calloc(sizeof(int), n);
    int count = 0;

    for(int i = 0; i < n; ++i)
    {
        if(vertices[i] == 0)
        {
            ++count;
            DFS_recur(g, vertices, n, i);
        }
    }

    free(vertices);
    return count;
}

void DFS_recur(int **g, int *vertices, int n, int i)
{
    vertices[i] = 1;

    for(int j = 0; j < n; ++j)
    {
        if(g[i][j] == 1 && vertices[j] == 0)
            DFS_recur(g, vertices, n, j);
    }
}

int BFS_main(int **g, int n)
{
    int *vertices = (int*)calloc(sizeof(int), n);
    int count = 0;

    for(int i = 0; i < n; ++i)
    {
        if(vertices[i] == 0)
        {
            ++count;
            BFS_recur(g, vertices, n, i);
        }
    }

    free(vertices);
    return count;
}

void BFS_recur(int **g, int *vertices, int n, int i)
{
    struct header h;
    initialize(&h);

    vertices[i] = 1;
    insert(&h, i);

    while(notempty(&h))
    {
        int x = dequeue(&h);
        for(int j = 0; j < n; ++j)
        {
            if(g[x][j] == 1 && vertices[j] == 0)
            {
                vertices[j] = 1;
                insert(&h, j);
            }
        }
    }
}

void initialize(struct header *h)
{
    h->head = NULL;
}

void insert(struct header *h, int vertex)
{  
    struct queue *temp = (struct queue*)malloc(sizeof(struct queue));
    temp->link = NULL;
    temp->vertex = vertex;

    if(h->head == NULL)
    {
        h->head = temp;
        return;
    }
    else
    {
        struct queue *p = h->head;
        while(p->link != NULL)
            p = p->link;

        p->link = temp;
    }
}

int dequeue(struct header *h)
{
    if(h->head == NULL) return -1;
    
    int x;
    if(h->head->link = NULL)
    {
        x = h->head->vertex;
        free(h->head->link);
        h->head = NULL;
    }
    else
    {
        struct queue *p = h->head;
        h->head = h->head->link;
        x = p->vertex;
        free(p);
    }
    return x;
}

int notempty(struct header *h)
{
    if(h->head == NULL) return 0;
    return 1;
}