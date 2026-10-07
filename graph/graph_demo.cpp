#include "graph.h"

int main()
{
    Graph<int> g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    cout<<"Adjacency List\n";
    cout<<g;

    cout<<"\nDFS Traversal: ";
    g.DFS(0);

    cout<<"BFS Traversal: ";
    g.BFS(0);

    return 0;
}