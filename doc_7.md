# Question 7: Dijkstra’s Shortest Path Algorithm

## Data Structure Used
- Graph is represented using adjacency matrix.  
- Arrays `dist[]` and `visited[]` are used to track distances and visited vertices.

## Functions
- minDistance(): Finds the vertex with the minimum distance that is not yet visited.  
- dijkstra(): Implements Dijkstra's algorithm to compute shortest paths from source.  

## Main Function
- Takes number of vertices and edges.  
- Inputs edges along with their weights.  
- Takes source vertex from the user.  
- Prints shortest distance from source to all other vertices.

## Sample Output
Enter number of vertices: 5  
Enter number of edges: 7  
Enter edge 1 (u v weight): 0 1 2  
Enter edge 2 (u v weight): 0 3 6  
Enter edge 3 (u v weight): 1 2 3  
Enter edge 4 (u v weight): 1 3 8  
Enter edge 5 (u v weight): 1 4 5  
Enter edge 6 (u v weight): 2 4 7  
Enter edge 7 (u v weight): 3 4 9  
Enter source vertex: 0  
Vertex 	 Distance from Source  
0 	 0  
1 	 2  
2 	 5  
3 	 6  
4 	 7
