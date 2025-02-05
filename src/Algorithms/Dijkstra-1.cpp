#include <iostream>
#include <limits.h>

#define V 9

int findMinDist(int distances[], bool processedSet[]) {
    int minVal = INT_MAX, minIndex;
    for (int i = 0; i < V; i++)
        if (processedSet[i] == false && distances[i] <= minVal)
            minVal = distances[i], minIndex = i;
    return minIndex;
}

void displayResults(int distances[], int n) {
    std::cout << "Vertex Distance from Start Point\n";
    for (int i = 0; i < V; i++)
        std::cout << "\t" << i << " \t\t\t\t " << distances[i] << "\n";
}

void dijkstra(int graph[V][V], int start) {
    int distances[V];
    bool processedSet[V];
    for (int i = 0; i < V; i++)
        distances[i] = INT_MAX, processedSet[i] = false;

    distances[start] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDist(distances, processedSet);
        processedSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!processedSet[v] && graph[u][v] && distances[u] != INT_MAX
                && distances[u] + graph[u][v] < distances[v])
                distances[v] = distances[u] + graph[u][v];
        }
    }
    displayResults(distances, V);
}

int main() {
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph, 0);

    return 0;
}
