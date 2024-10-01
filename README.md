# Graph Traversal in C
This project implements a graph data structure using adjacency lists in C, 
and demonstrates two fundamental graph traversal algorithms: **Depth-First Search (DFS)** and **Breadth-First Search (BFS)**. 
The project allows users to input the number of vertices, edges, and the type of graph (directed or undirected), and perform DFS and BFS starting from vertex 0.

## Features
- Graph creation using adjacency lists.
- Support for both **directed** and **undirected** graphs.
- Adding edges to the graph.
- Graph traversal using:
  - Depth-First Search (DFS) (recursive)
  - Breadth-First Search (BFS) (using a queue)
- Simple user interaction through the command line.

## Getting Started
### Prerequisites
- A C compiler (e.g., GCC) installed on your machine.

### Compilation
To compile the program, run the following command in your terminal:

## Compilation
To compile the program, run the following command in your terminal:
`gcc -o graph_traversal main.c graph.c`

## Running the Program
After compilation, run the program using the following command:
`./graph_traversal`

The program will prompt you for the number of vertices and the type of graph (directed or undirected). 
Then, you will input the edges of the graph.

## Example Input
```
Enter the number of vertices in the graph >> 4

## Main Menu
1. Directed graph
2. Undirected graph
Select a graph type (1~2) >> 1

Enter the number of destinations of vertex 0 >> 2
Vertex 0: destination 1 >> 1
Vertex 0: destination 2 >> 2

Enter the number of destinations of vertex 1 >> 1
Vertex 1: destination 1 >> 2

Enter the number of destinations of vertex 2 >> 1
Vertex 2: destination 1 >> 3

Enter the number of destinations of vertex 3 >> 0
```


## Example Output
```
Adjacency list of vertex 0
 head -> 1 -> 2

Adjacency list of vertex 1
 head -> 2

Adjacency list of vertex 2
 head -> 3

Adjacency list of vertex 3
 head 

DFS traversal: 0 1 2 3 
BFS traversal: 0 1 2 3
```

## Project Structure
The project is organized into the following files:

1. `main.c`: Contains the main function for handling user interaction and graph traversal.
2. `graph.c`: Implements the graph creation, edge addition, and traversal functions (DFS and BFS).
3. `graph.h`: Header file that contains the structure definitions and function declarations.
