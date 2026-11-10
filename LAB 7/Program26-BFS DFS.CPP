#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfsRecursiveUtil(int curr, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[curr] = true;
    cout << curr << " ";
    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            dfsRecursiveUtil(neighbor, adj, visited);
        }
    }
}

void dfsRecursive(int start, const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    dfsRecursiveUtil(start, adj, visited);
}

void dfsIterative(int start, const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            cout << curr << " ";
        }

        for (int i = adj[curr].size() - 1; i >= 0; i--) {
            int neighbor = adj[curr][i];
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    cout << "BFS Traversal: ";
    bfs(0, adj, V);
    cout << "\n";

    cout << "DFS (Recursive): ";
    dfsRecursive(0, adj, V);
    cout << "\n";

    cout << "DFS (Iterative): ";
    dfsIterative(0, adj, V);
    cout << "\n";

    return 0;
}