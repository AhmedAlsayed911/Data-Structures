#include "../include/Graph.h"
#include <iostream>
#include <queue>
#include <algorithm>

Graph::Graph(int v, bool directed)
{
    this->vertices = v;
    this->directed = directed;
    adjList.resize(v);
}

void Graph::addEdge(int src, int dest)
{
    adjList[src].push_back(dest);
    if (!directed)
        adjList[dest].push_back(src);
}

void Graph::removeEdge(int src, int dest)
{
    adjList[src].remove(dest);
    if (!directed)
        adjList[dest].remove(src);
}

bool Graph::hasEdge(int src, int dest)
{
    for (int v : adjList[src])
        if (v == dest) return true;
    return false;
}

void Graph::bfs(int start)
{
    std::vector<bool> visited(vertices, false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        std::cout << v << " ";

        for (int neighbor : adjList[v])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::dfsHelper(int v, std::vector<bool>& visited)
{
    visited[v] = true;
    std::cout << v << " ";

    for (int neighbor : adjList[v])
        if (!visited[neighbor])
            dfsHelper(neighbor, visited);
}

void Graph::dfs(int start)
{
    std::vector<bool> visited(vertices, false);
    dfsHelper(start, visited);
    std::cout << std::endl;
}

void Graph::display()
{
    for (int i = 0; i < vertices; i++)
    {
        std::cout << i << " -> ";
        for (int v : adjList[i])
            std::cout << v << " ";
        std::cout << std::endl;
    }
}

int Graph::getVertices()
{
    return vertices;
}
