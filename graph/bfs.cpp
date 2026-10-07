#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[100][100] = {0};

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

    bool visited[100] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}