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

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    int distance[100];
    bool visited[100];

    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDistance = INT_MAX;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] &&
                !visited[v] &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances:" << endl;

    for (int i = 0; i < n; i++) {
        cout << source << " -> " << i << " = ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }

    return 0;
}