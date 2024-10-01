#include "graph.h"

// Create a new graph with specified number of vertices
Graph_t* createGraph(int verticeNum) {
    Graph_t* graph = (Graph_t*)malloc(sizeof(Graph_t));
    graph->verticeNum = verticeNum;
    graph->adjListArr = (adjList_t*)malloc(sizeof(adjList_t) * verticeNum);
    graph->visited = (bool*)malloc(sizeof(bool) * verticeNum);

    // Initialize adjacency list and visited array
    for (int i = 0; i < verticeNum; i++) {
        graph->adjListArr[i].head = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Create a new node with given data
Node_t* createNewNode(int data) {
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to the graph
void addEdge(Graph_t* graph, int src, int dest, bool isDirected) {
    Node_t* destNode = createNewNode(dest);

    // Add edge from src to dest
    if (graph->adjListArr[src].head == NULL) {
        graph->adjListArr[src].head = destNode;
    } else {
        Node_t* temp = graph->adjListArr[src].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = destNode;
    }

    // If the graph is undirected, add an edge from dest to src
    if (!isDirected) {
        destNode = createNewNode(src);
        if (graph->adjListArr[dest].head == NULL) {
            graph->adjListArr[dest].head = destNode;
        } else {
            Node_t* temp = graph->adjListArr[dest].head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = destNode;
        }
    }
}

// Print the graph
void printGraph(Graph_t* graph) {
    for (int i = 0; i < graph->verticeNum; i++) {
        Node_t* temp = graph->adjListArr[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth-First Search (DFS)
void DFS(Graph_t* graph, int start) {
    Node_t* temp = graph->adjListArr[start].head;
    graph->visited[start] = true;
    printf("%d ", start);

    while (temp != NULL) {
        if (!graph->visited[temp->data]) {
            DFS(graph, temp->data);
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS)
void BFS(Graph_t* graph, int start) {
    int* queue = (int*)malloc(sizeof(int) * graph->verticeNum);
    int front = -1;
    int rear = -1;
    Node_t* temp;

    // Reinitialize the visited array
    for (int i = 0; i < graph->verticeNum; i++) {
        graph->visited[i] = false;
    }

    queue[++rear] = start;
    graph->visited[start] = true;

    while (front < rear) {
        start = queue[++front];
        printf("%d ", start);
        temp = graph->adjListArr[start].head;

        while (temp != NULL) {
            if (!graph->visited[temp->data]) {
                queue[++rear] = temp->data;
                graph->visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }

    free(queue);
}
