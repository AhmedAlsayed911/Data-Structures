#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

class Graph
{
private:
    int vertices;
    bool directed;
    std::vector<std::list<int>> adjList;

    void dfsHelper(int v, std::vector<bool>& visited);

public:
    Graph(int v, bool directed = false);

    void addEdge(int src, int dest);
    void removeEdge(int src, int dest);
    bool hasEdge(int src, int dest);

    void bfs(int start);
    void dfs(int start);

    void display();
    int getVertices();
};

#endif
