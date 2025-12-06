//BFS using adjacency matrix

#include <iostream>
#include <queue>
using namespace std;

// Function to perform BFS using adjacency matrix
void BFS(int** adjacencyMatrix, int numVertices, int source) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS traversal
    queue<int> q;
    // Enqueue the starting vertex and mark it as visited
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        // Dequeue a vertex from the queue
        int u = q.front();
        q.pop();
        // Print it
        cout << u << " ";

        // Iterate through all vertices
        for (int v = 0; v < numVertices; v++) {
            // Check if there is an edge between u and vertex v
            // and if vertex v is not visited
            if (adjacencyMatrix[u][v] == 1 && !visited[v]) {
                // Enqueue the vertex v and mark it as visited
                q.push(v);
                visited[v] = true;
            }
        }
    }

    delete[] visited;
}

int main() {
    int numVertices = 5;
    // Create an adjacency matrix for the graph
    int** adjacencyMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjacencyMatrix[i] = new int[numVertices];
    }
    // Initialize the adjacency matrix
    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[0][3] = 1;
    adjacencyMatrix[3][2] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[2][3] = 1;
    adjacencyMatrix[3][4] = 1;

    int startVertex = 0; // Starting vertex for BFS

    // Perform BFS traversal
    cout << "BFS traversal starting from vertex " << startVertex << ":" << endl;
    BFS(adjacencyMatrix, numVertices, startVertex);

    return 0;
}