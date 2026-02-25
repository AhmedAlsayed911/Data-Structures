#include <iostream>
#include "../include/Graph.h"

int main()
{
    Graph g(6, false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    std::cout << "Adjacency List:" << std::endl;
    g.display();

    std::cout << "BFS from 0: ";
    g.bfs(0);

    std::cout << "DFS from 0: ";
    g.dfs(0);

    std::cout << "Has edge 0->1: " << (g.hasEdge(0, 1) ? "Yes" : "No") << std::endl;

    g.removeEdge(0, 1);
    std::cout << "After removing edge 0->1:" << std::endl;
    g.display();

    return 0;
}
