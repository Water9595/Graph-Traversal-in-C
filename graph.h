#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node_t;

typedef struct adjList {
    Node_t* head;  // Head node of adjacency list (stores the address of the first node)
} adjList_t;

typedef struct Graph {
    int verticeNum;
    adjList_t* adjListArr; // Array of adjacency lists
    bool* visited;         // Array to track visited vertices
} Graph_t;

// Function declarations
Graph_t* createGraph(int verticeNum);
Node_t* createNewNode(int data);
void addEdge(Graph_t* graph, int src, int dest, bool isDirected);
void printGraph(Graph_t* graph);
void DFS(Graph_t* graph, int start);
void BFS(Graph_t* graph, int start);

#endif
