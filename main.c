#include "graph.h"

int main() {
    int vNum = 0;           // Input - number of vertices in the graph
    int selecGraph = 0;     // Input - choose directed or undirected graph
    int edgeNum = 0;        // Input - number of edges for each vertex
    int neighbor = 0;       // Input - neighbor vertex number
    Graph_t* graph;

    printf("Enter the number of vertices in the graph >> ");
    scanf("%d", &vNum);
    graph = createGraph(vNum);

    do {
        printf("\n** Main Menu **\n");
        printf("1. Directed graph\n");
        printf("2. Undirected graph\n");
        printf("Select a graph type (1~2) >> ");
        scanf("%d", &selecGraph);
    } while (selecGraph != 1 && selecGraph != 2);

    for (int i = 0; i < vNum; i++) {
        printf("Enter the number of destinations of vertex %d >> ", i);
        scanf("%d", &edgeNum);

        for (int j = 0; j < edgeNum; j++) {
            printf("Vertex %d: destination %d >> ", i, j + 1);
            scanf("%d", &neighbor);

            if (selecGraph == 1) {
                addEdge(graph, i, neighbor, 1);  // Directed graph
            } else if (selecGraph == 2) {
                addEdge(graph, i, neighbor, 0);  // Undirected graph
            }
        }
    }

    printGraph(graph);

    printf("\n\nDFS traversal: ");
    DFS(graph, 0);
    printf("\n");

    printf("\n\nBFS traversal: ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}
