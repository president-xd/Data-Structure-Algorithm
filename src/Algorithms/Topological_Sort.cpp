#include <iostream>
#include <vector>
#include <stack>

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
    }

    const vector<vector<int>>& getAdjacencyList() const {
        return adjacencyList;
    }

    int countVertices() const {
        return vertices;
    }
};

class TopologicalSort {
private:
    void dfs(int node, vector<bool>& visited, stack<int>& stack, const vector<vector<int>>& adjList) {
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, stack, adjList);
            }
        }
        stack.push(node);
    }

public:
    void topologicalSort(const Graph& graph) {
        const vector<vector<int>>& adjacencyList = graph.getAdjacencyList();
        vector<bool> visited(graph.countVertices(), false);
        stack<int> stack;
        for (int i = 0; i < graph.countVertices(); ++i) {
            if (!visited[i]) {
                dfs(i, visited, stack, adjacencyList);
            }
        }

        // Output topological order
        cout << "Topological Order: ";
        while (!stack.empty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    TopologicalSort topoSort;
    topoSort.topologicalSort(graph);

    return 0;
}
