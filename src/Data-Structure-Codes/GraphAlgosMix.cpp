#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class Graphs {
public:
    unordered_map<int, list<int>> adjList; // adjacency list representation

    // Constructor to initialize the graph
    Graphs() {}

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool isDirected) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    // Function to print the adjacency list of the graph
    void printAjList() {
        for (auto& i : adjList) {
            cout << i.first << ": ";
            for (auto& j : i.second) {
                cout << j << " -> ";
            }
            cout << "NULL" << endl;
        }
    }

    // BFS helper function
    void bfs_helper(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& result, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            result.push_back(frontNode);

            for (auto& neighbor : adjList[frontNode]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    // BFS function to traverse the entire graph
    vector<int> BFS(int V, vector<pair<int, int>>& edges, bool isDirected) {
        vector<int> result;
        unordered_map<int, bool> visited;

        // Prepare adjacency list from edges
        for (auto& edge : edges) {
            addEdge(edge.first, edge.second, isDirected);
        }

        // Perform BFS from every unvisited node
        for (auto& node : adjList) {
            int start = node.first;
            if (!visited[start]) {
                bfs_helper(adjList, visited, result, start);
            }
        }

        return result;
    }

    // DFS helper function
    void dfs_helper(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, vector<int>& component) {
        // Store in component
        component.push_back(node);

        // Mark Visited
        visited[node] = true;

        // Recursive call for each node's neighbors
        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs_helper(neighbor, visited, adj, component);
            }
        }
    }

    // DFS function to traverse the entire graph and return connected components
    vector<vector<int>> DFS(int V, vector<pair<int, int>>& edges) {
        unordered_map<int, list<int>> adj;

        // Prepare adjacency list from edges
        for (auto& edge : edges) {
            addEdge(edge.first, edge.second, true); // Assuming directed for DFS as well
        }

        vector<vector<int>> result;
        unordered_map<int, bool> visited;

        // Perform DFS from each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs_helper(i, visited, adj, component);
                result.push_back(component);
            }
        }

        return result;
    }

    // Function to perform Dijkstra's algorithm
    vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
        // First Creating Adjacency List
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < edges; i++) {
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];

            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        // Creation of distance array with infinite value initially
        vector<int> dist(vertices, INT_MAX);

        // Creation of set on basis of distance, node
        set<pair<int, int>> st;

        // Initialize distance and set with source node
        dist[source] = 0;
        st.insert(make_pair(0, source));

        while (!st.empty()) {
            // Fetch the Record
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;

            // Erase the top record
            st.erase(st.begin());

            // Traverse the neighbors
            for (auto neighbor : adj[topNode]) {
                if (nodeDistance + neighbor.second < dist[neighbor.first]) {
                    auto record = st.find(make_pair(dist[neighbor.first], neighbor.first));
                    // If record found, then erase it
                    if (record != st.end()) {
                        st.erase(record);
                    }

                    // Updating Distance
                    dist[neighbor.first] = nodeDistance + neighbor.second;

                    // Record push in set
                    st.insert(make_pair(dist[neighbor.first], neighbor.first));
                }
            }
        }

        return dist;
    }

    // DFS helper function for topological sorting
    void topo_sort_helper(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, stack<int>& topoStack) {
        // Mark the node as visited
        visited[node] = true;

        // Visit all neighbors of the node
        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                topo_sort_helper(neighbor, visited, adj, topoStack);
            }
        }

        // Push the current node to the stack after visiting its neighbors
        topoStack.push(node);
    }

    // Function to perform topological sort
    vector<int> topological_sort(int V, vector<pair<int, int>>& edges) {
        unordered_map<int, list<int>> adj;

        // Initialize adjacency list for all nodes
        for (int i = 0; i < V; i++) {
            adj[i] = {};
        }

        // Add directed edges to adjacency list
        for (auto& edge : edges) {
            adj[edge.first].push_back(edge.second);
        }

        stack<int> topoStack;
        unordered_map<int, bool> visited;

        // Perform DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topo_sort_helper(i, visited, adj, topoStack);
            }
        }

        // Extract the topological order from the stack
        vector<int> topoOrder;
        while (!topoStack.empty()) {
            topoOrder.push_back(topoStack.top());
            topoStack.pop();
        }

        return topoOrder;
    }

};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graphs g;
    vector<pair<int, int>> edges;

    cout << "Enter all edges (u v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u, v });
    }

    bool isDirected;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    vector<int> resultBFS = g.BFS(n, edges, isDirected);
    cout << "BFS traversal result: ";
    for (int node : resultBFS) {
        cout << node << " ";
    }
    cout << endl;

    vector<vector<int>> resultDFS = g.DFS(n, edges);
    cout << "DFS connected components: " << endl;
    for (auto& component : resultDFS) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    int dijkstraSource;
    cout << "Enter the source node for Dijkstra's algorithm: ";
    cin >> dijkstraSource;

    cout << "Enter the number of weighted edges for Dijkstra's algorithm: ";
    cin >> m;

    vector<vector<int>> weightedEdges(m, vector<int>(3));
    cout << "Enter all weighted edges (u v w): " << endl;
    for (int i = 0; i < m; i++) {
        cin >> weightedEdges[i][0] >> weightedEdges[i][1] >> weightedEdges[i][2];
    }

    vector<int> resultDijkstra = g.dijkstra(weightedEdges, n, m, dijkstraSource);
    cout << "Dijkstra's shortest path result from source " << dijkstraSource << ": ";
    for (int dist : resultDijkstra) {
        cout << dist << " ";
    }
    cout << endl;

    vector<pair<int, int>> topoEdges = { {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1} };
    vector<int> topoOrder = g.topological_sort(6, topoEdges);
    cout << "Topological Sort Order: ";
    for (auto& node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

