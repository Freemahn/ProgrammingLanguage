#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include "Graph.h"
void foo(unsigned a){
    std::cout << a << std::endl;
}
TEST(correctness, correctness_addNode_Test)
{
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();


    EXPECT_TRUE(g.getNodesCount() == 5);

}

TEST(correctness, correctness_dfs_Test)
{
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.dfs(0, 4, foo);
    EXPECT_TRUE(g.getNodesCount() == 5);
}
