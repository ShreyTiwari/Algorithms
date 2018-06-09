#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct header
{
    struct queue *head;
};

struct queue
{
    int vertex;
    struct queue *link;
};

int DFS_main(int **g, int n);
void DFS_recur(int **g, int *vertices, int n, int i);

int BFS_main(int **g, int n);
void BFS_recur(int **g, int *vertices, int n, int i);

double time_elapsed(struct timespec *start, struct timespec *end);

void initialize(struct header *h);
void insert(struct header *h, int vertex);
int dequeue(struct header *h);
int notempty(struct header *h);