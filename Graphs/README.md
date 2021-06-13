# Kruskal's Algorithm
We are given a graph, our aim is to find the minimum spanning tree(MST).

### Input format:
    1. n - number of vertices
    2. e - number of edges
    3. e lines in the form of " v1 v2 w "
        v1 - first vertex
        v2 - second vertex 
        w - weight of the edges connecting v1 and v2

Our aim is to find a tree having all the vertices with edges of minimum weights. 
So, we do the following:
    1. Sort the array on the basis of weights.
    2. Take each edge one by one and check whether adding that edge to the tree makes a cycle. 
    3. How do we check whether it makes a cycle? - Union Find Algorithm.

## Union Find Algorithm:
It is an algorithm to find whether there is a cycle in a graph.
We take an array 'A' of size n. A[i] = i. This array determine the parents of each vertex. We have initialized it with i.
Now let's say we take 1st edge of the sorted array. 
v1 v2 w
if v1 and v2 have same parents i.e. A[v1] = A[v2], then connecting them would lead us to a cycle which we do not want. Hence we take or reject an edge based on whether or not the vertices of that edge have same parents.
