#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices = 4;
    
    int adjMatrix[4][4] = {0};
    auto addEdgeMatrix = [&](int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    };
    
    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 2);
    addEdgeMatrix(1, 2);
    addEdgeMatrix(2, 3);

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> adjList(vertices);
    auto addEdgeList = [&](int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    };

    addEdgeList(0, 1);
    addEdgeList(0, 2);
    addEdgeList(1, 2);
    addEdgeList(2, 3);

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}