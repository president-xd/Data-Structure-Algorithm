#include <iostream>
#include <vector>

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

class DFS {
private:
    void dfsUtil(int node, vector<bool>& visited, vector<int>& component, const vector<vector<int>>& adjList) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, component, adjList);
            }
        }
    }

public:
    void findConnectedComponents(const Graph& graph) {
        const vector<vector<int>>& adjacencyList = graph.getAdjacencyList();
        vector<bool> visited(graph.countVertices(), false);
        vector<vector<int>> components;
        for (int i = 0; i < graph.countVertices(); ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfsUtil(i, visited, component, adjacencyList);
                components.push_back(component);
            }
        }

        // Output connected components
        for (const auto& component : components) {
            cout << "Connected Component:";
            for (int node : component) {
                cout << " " << node;
            }
            cout << endl;
        }
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

    DFS dfs;
    dfs.findConnectedComponents(graph);

    return 0;
}
