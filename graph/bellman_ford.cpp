#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

int main() {
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    Edge graph[100];

    cout << "Enter edges (u v weight):" << endl;

    for (int i = 0; i < edges; i++) {
        cin >> graph[i].u;
        cin >> graph[i].v;
        cin >> graph[i].weight;
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    int distance[100];

    for (int i = 0; i < n; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edges; j++) {

            int u = graph[j].u;
            int v = graph[j].v;
            int weight = graph[j].weight;

            if (distance[u] != INT_MAX &&
                distance[u] + weight < distance[v]) {

                distance[v] = distance[u] + weight;
            }
        }
    }

    bool negativeCycle = false;

    for (int i = 0; i < edges; i++) {
        int u = graph[i].u;
        int v = graph[i].v;
        int weight = graph[i].weight;

        if (distance[u] != INT_MAX &&
            distance[u] + weight < distance[v]) {

            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative weight cycle exists.";
    }
    else {
        cout << "Shortest distances:" << endl;

        for (int i = 0; i < n; i++) {
            cout << source << " -> " << i << " = ";

            if (distance[i] == INT_MAX)
                cout << "INF";
            else
                cout << distance[i];

            cout << endl;
        }
    }

    return 0;
}