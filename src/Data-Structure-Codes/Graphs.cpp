#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;
// Number of vertices
#define V 6

class Graph {
private:
    // Adjacency list to represent the graph
    vector<vector<int> > adjList;
    // Boolean flag to indicate if the graph is directed
    bool isDirected;

public:
    // Constructor to initialize the graph
    // Parameters: vertices - number of vertices in the
    // graph
    //  directed - flag to indicate if the graph is directed
    //  (default is false)
    Graph(int vertices, bool directed = false){
        // Resize the adjacency list to accommodate the
        // vertices
        adjList.resize(vertices);
        // Set the directed flag
        isDirected = directed;
    }

    // Function to add an edge to the graph
    // Parameters: src - source vertex
    // dest - destination vertex
    void addEdge(int src, int dest){
        // Add the destination to the adjacency list of the
        // source
        adjList[src].push_back(dest);
        // If the graph is undirected
        if (!isDirected) {
            // Add the source to the adjacency list of the
            // destination
            adjList[dest].push_back(src);
        }
    }

    // Function to print the adjacency list of the graph
    void printGraph(){
        // Iterate through each vertex
        for (int i = 0; i < adjList.size(); ++i) {
            // Print the vertex
            cout << i << ": ";
            // Iterate through the adjacency list of the
            // vertex
            for (int j = 0; j < adjList[i].size(); ++j) {
                // Print each adjacent vertex
                cout << adjList[i][j] << " -> ";
            }
            // Indicate the end of the adjacency list
            cout << "NULL" << endl;
        }
    }
};

void initAdjMatrix(int adjMatrix[V][V]){
    // Initialize all elements of the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}



// Function to add an edge to the graph
void addEdge(int adjMatrix[V][V], int u, int v, bool direction){
	
	// Mark if the direction is for undirected graph
	if (direction){
		
    	adjMatrix[u][v] = 1;
	} else{
		// If it is a undirected graph
    	adjMatrix[v][u] = 1;
	}
}

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[V][V]){
    // Print the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Class for Graph
class Graphs{
	public:
		unordered_map <int, list<int>>adjList;
		
		void addEdge(int u, int v, bool isdirected){
			// If Direction == 0, undirected
			// If Directed == 1, Directed
			adjList[u].push_back(v);
			
			if (isdirected){
				adjList[v].push_back(v);
			}
		}
		
		void printAjList(){
			for (auto i:adjList){
				cout << i.first << " --> ";
				for (auto j:i.second){
					cout << j << ", ";
				}
				cout << endl;
			}
		}
};

// Main Function
int main(){
	
	// For Adjcent Matrix
	/*
    int adjMatrix[V][V];

    // Initialize the adjacency matrix
    initAdjMatrix(adjMatrix);

    // Add edges to the graph
    addEdge(adjMatrix, 0, 3, true);
    addEdge(adjMatrix, 0, 4, true);
    addEdge(adjMatrix, 1, 4, true);
    addEdge(adjMatrix, 1, 5, true);
    addEdge(adjMatrix, 1, 2, true);
    addEdge(adjMatrix, 2, 5, true);
    addEdge(adjMatrix, 2, 3, true);
    addEdge(adjMatrix, 3, 5, true);
    addEdge(adjMatrix, 4, 5, true);

    cout << "Adjacency Matrix:" << endl;
    // Print the adjacency matrix
    printAdjMatrix(adjMatrix);
    */
    
    /*
    // For Adjacent List
    // Number of vertices in the graph
    int vertices = 3;

    // Undirected Graph Example
    Graph undirectedGraph(vertices);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 2);

    // Print the adjacency list of the undirected graph
    cout << "Undirected Graph Adjacency List:" << endl;
    undirectedGraph.printGraph();

    cout << endl;

    // Directed Graph Example
    Graph directedGraph(vertices, true);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 0);
    directedGraph.addEdge(2, 0);

    // Print the adjacency list of the directed graph
    cout << "Directed Graph Adjacency List:" << endl;
    directedGraph.printGraph();
	*/
	
	int n;
	cout << "Enter the number of nodes : ";
	cin >> n;
	
	int m;
	cout << "Enter number of edges : ";
	cin >> m;
	
	Graphs g;
	
	cout << "Enter all Edges : ";
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		
		// Creating an Undirected Graph
		g.addEdge(u, v, false);
	}
	
	g.printAjList();
	
    return 0;
}
