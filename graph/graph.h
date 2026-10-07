#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<class T>
class Graph
{
    int V;
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v]=true;
        cout<<v<<" ";

        for(int u:adj[v])
            if(!visited[u])
                DFSUtil(u,visited);
    }

public:

    Graph(int vertices)
    {
        V=vertices;
        adj.resize(V);
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start)
    {
        vector<bool> visited(V,false);
        DFSUtil(start,visited);
        cout<<endl;
    }

    void BFS(int start)
    {
        vector<bool> visited(V,false);
        queue<int> q;

        visited[start]=true;
        q.push(start);

        while(!q.empty())
        {
            int v=q.front();
            q.pop();

            cout<<v<<" ";

            for(int u:adj[v])
            {
                if(!visited[u])
                {
                    visited[u]=true;
                    q.push(u);
                }
            }
        }
        cout<<endl;
    }

    void display()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<" : ";

            for(int x:adj[i])
                cout<<x<<" ";

            cout<<endl;
        }
    }

    friend ostream& operator<<(ostream &out, Graph<T> &g)
    {
        g.display();
        return out;
    }
};

#endif