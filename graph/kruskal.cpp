#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    parent[a] = b;
}

int main() {
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    Edge graph[100];

    cout << "Enter edges (u v weight):" << endl;

    for (int i = 0; i < edges; i++) {
        cin >> graph[i].u >> graph[i].v >> graph[i].weight;
    }

    sort(graph, graph + edges, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Edges in Minimum Spanning Tree:" << endl;

    int total = 0;
    int count = 0;

    for (int i = 0; i < edges && count < n - 1; i++) {
        int u = graph[i].u;
        int v = graph[i].v;

        if (findParent(u) != findParent(v)) {
            cout << u << " - " << v
                 << " : " << graph[i].weight << endl;

            total += graph[i].weight;

            unionSet(u, v);

            count++;
        }
    }

    cout << "Total cost: " << total;

    return 0;
}