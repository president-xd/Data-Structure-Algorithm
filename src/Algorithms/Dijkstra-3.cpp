#include <iostream>
#include <vector>
#include <limits.h>
#include <stdio.h>

using namespace std;

#define INF INT_MAX

int findMinDist(vector<int>& distances, vector<bool>& processed, int numVertices) {
    int minDist = INF, minIndex;
    for (int i = 0; i < numVertices; i++) {
        if (!processed[i] && distances[i] <= minDist) {
            minDist = distances[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void displayResults(const vector<int>& distances, int numVertices) {
    printf("Node Distance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("\t%d \t\t %d\n", i, distances[i]);
    }
}

void dijkstra(vector<vector<int>>& graph, int startNode, int numVertices) {
    vector<int> distances(numVertices, INF);
    vector<bool> processed(numVertices, false);
    distances[startNode] = 0;
    for (int count = 0; count < numVertices - 1; count++) {
        int u = findMinDist(distances, processed, numVertices);
        processed[u] = true;
        for (int v = 0; v < numVertices; v++) {
            if (!processed[v] && graph[u][v] && distances[u] != INF
                && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
    displayResults(distances, numVertices);
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numVertices;
    if (numVertices <= 0) {
        cout << "Number of nodes must be greater than 0." << endl;
        return 1;
    }
    cout << "Enter the number of connections: ";
    cin >> numEdges;
    if (numEdges < 0) {
        cout << "Number of connections cannot be negative." << endl;
        return 1;
    }

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));
    cout << "Enter the connections (node1 node2 weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        if (node1 < 0 || node1 >= numVertices || node2 < 0 || node2 >= numVertices) {
            cout << "Invalid connection: (" << node1 << ", " << node2 << "). Node indices must be between 0 and " << numVertices - 1 << "." << endl;
            return 1;
        }
        if (weight < 0) {
            cout << "Weight cannot be negative." << endl;
            return 1;
        }
        graph[node1][node2] = weight;
        graph[node2][node1] = weight;
    }

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;
    if (startNode < 0 || startNode >= numVertices) {
        cout << "Invalid start node. It must be between 0 and " << numVertices - 1 << "." << endl;
        return 1;
    }

    dijkstra(graph, startNode, numVertices);
    return 0;
}
