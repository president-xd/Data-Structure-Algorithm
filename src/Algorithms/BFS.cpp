#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v) {
        adjacencyList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    const vector<vector<int>>& getAdjacencyList() const {
        return adjacencyList;
    }

    int countVertices() const {
        return vertices;
    }
};

class BFS {
public:
    void shortestPath(const Graph& graph, int source, int destination) {
        const vector<vector<int>>& adjacencyList = graph.getAdjacencyList();
        queue<int> q;
        vector<int> parent(graph.countVertices(), -1);
        vector<bool> visited(graph.countVertices(), false);
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                break;
            }
            for (int neighbor : adjacencyList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = node;
                }
            }
        }

        // Backtrack to find the path
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        // Output the path
        cout << "Shortest Path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    BFS bfs;
    int source = 0;
    int destination = 6;
    bfs.shortestPath(graph, source, destination);

    return 0;
}
