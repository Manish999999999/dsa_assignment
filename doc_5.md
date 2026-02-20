# Question 5: BFS and DFS Traversal of Graph

## Data Structure Used
Graph is represented using adjacency matrix.  
Visited array is used to keep track of visited nodes.  
Queue is used for BFS.

## Functions
- BFS(): Performs breadth-first search.  
- DFS(): Performs depth-first search using recursion.  
- enqueue(), dequeue(): Used for BFS queue operations.  

## Main Function
- Takes number of vertices and edges.  
- Inputs edges to build adjacency matrix.  
- Asks for starting vertex.  
- Prints BFS and DFS traversal from starting vertex.

## Sample Output
Enter number of vertices: 4  
Enter number of edges: 4  
Enter edge 1 (u v): 0 1  
Enter edge 2 (u v): 0 2  
Enter edge 3 (u v): 1 2  
Enter edge 4 (u v): 2 3  
Enter starting vertex: 0  
BFS: 0 1 2 3  
DFS: 0 1 2 3
