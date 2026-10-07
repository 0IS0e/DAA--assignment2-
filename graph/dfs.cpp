#include <iostream>
using namespace std;

int graph[100][100];
bool visited[100];

void dfs(int vertex, int n) {
    visited[vertex] = true;

    cout << vertex << " ";

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges: " << endl;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";

    dfs(start, n);

    return 0;
}