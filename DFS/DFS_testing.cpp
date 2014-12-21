#include <algorithm>
#include <gtest/gtest.h>
#include "Graph.h"

void discoverNode(unsigned a) {
    std::cout << "discover " << a << std::endl;
}

void startNode(unsigned a) {
    std::cout << "start " << a << std::endl;
}

void endNode(unsigned a) {
    std::cout << "end " << a << std::endl;
}

TEST(correctness, graph_addNode_Test) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    EXPECT_TRUE(g.getNodesCount() == 5);

}

TEST(correctness, graph_dfs_Test) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.dfs(startNode, endNode, discoverNode);
    EXPECT_TRUE(g.getNodesCount() == 5);
}


TEST(correctness, graph_payload_Test) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(2, 3);
    g[2] = 5;
    EXPECT_TRUE(g[2] == 5);

}
TEST(correctness, graph_file) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g[1] = 51;
    g[2] = 4;
    g[4] = 123;
    g.saveToFile("imafile.txt");
    Graph<int> g2;
    g2.loadFromFile("imafile.txt");
    EXPECT_TRUE(g.getNodesCount() == g2.getNodesCount());

}

