//Header file for alcoding_daa_lab.c

//Returns the smallest i for which A[i] < A[i-1] in the array A[0..n-1].
//Returns '-1' if there is no such i.
int SmallestOutofOrderIndex(int *A, int n);

//Returns the number of occurrences of key in the given sorted array.
//The given array is sorted in nondecreasing order, you can be sure of that.
//Hint: Binary Search
int CountOccurrencesInSorted(int* A, int n, int key);

//Graph g is given in the adjacency matrix g[0..n-1][0..n-1] format.
//Returns 1 if there is a topological order, and
// 0 if there is no topological order for the given graph.
//Updates topo_order, the array of n integers in topological order.
//Memory allocation for topo_order is already done by the caller.
//A topological order is an arrangement of integers from 
// 0 to n-1 for the given graph, if there is a topological order.
int toposort(int** g, int n, int* topo_order);
