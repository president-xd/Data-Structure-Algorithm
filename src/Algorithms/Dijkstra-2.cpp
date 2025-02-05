#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

struct Connection {
    int destination;
    int weight;
};

void shortestPath(int numVertices, vector<list<Connection>>& graph, int startNode) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    vector<int> distances(numVertices, INT_MAX);
    minHeap.push({0, startNode});
    distances[startNode] = 0;

    while (!minHeap.empty()) {
        int currentNode = minHeap.top().second;
        minHeap.pop();

        for (const auto& conn : graph[currentNode]) {
            int nextNode = conn.destination;
            int edgeWeight = conn.weight;
            if (distances[currentNode] + edgeWeight < distances[nextNode]) {
                distances[nextNode] = distances[currentNode] + edgeWeight;
                minHeap.push({distances[nextNode], nextNode});
            }
        }
    }

    cout << "Node Distance from Start\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "\t" << i << " \t\t " << distances[i] << "\n";
    }
}

int main() {
    int numVertices = 9;
    vector<list<Connection>> graph(numVertices);

    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});
    graph[2].push_back({8, 2});
    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});
    graph[4].push_back({3, 9});
    graph[4].push_back({5, 10});
    graph[5].push_back({2, 4});
    graph[5].push_back({3, 14});
    graph[5].push_back({4, 10});
    graph[5].push_back({6, 2});
    graph[6].push_back({5, 2});
    graph[6].push_back({7, 1});
    graph[6].push_back({8, 6});
    graph[7].push_back({0, 8});
    graph[7].push_back({1, 11});
    graph[7].push_back({6, 1});
    graph[7].push_back({8, 7});
    graph[8].push_back({2, 2});
    graph[8].push_back({6, 6});
    graph[8].push_back({7, 7});

    shortestPath(numVertices, graph, 0);

    return 0;
}
