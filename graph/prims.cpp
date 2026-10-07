#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[100][100];

    cout << "Enter adjacency matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int key[100];
    int parent[100];
    bool used[100];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        used[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int minKey = INT_MAX;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        used[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !used[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edges in Minimum Spanning Tree:" << endl;

    int total = 0;

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total cost: " << total;

    return 0;
}