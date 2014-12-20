#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <functional>
#include <stack>
#include <vector>

template<typename NodePayload>
class Graph {
public:
    typedef unsigned NodeHandle; // Unique ID for each node.
    typedef std::pair<NodeHandle, NodeHandle> EdgeHandle; // Pair of NodeHandle
    typedef std::function<void(NodeHandle const &)> NodeVisitor; // Custom function for node.
    typedef std::function<void(EdgeHandle const &)> EdgeVisitor; // Custom function for edge.

    Graph() = default; // Default constructor.
    ~Graph() = default; // Default destructor.
    void loadFromFile(std::string const &filename); // Load graph from file with specified filename.
    void saveToFile(std::string const &filename); // Save graph in file with specified filename.
    NodeHandle addNode(); // Add new node to graph. Return handle its node.
    void addEdge(NodeHandle const &a, NodeHandle const &b); // Add new edge to graph.
    void forEachNode(std::function<void(NodeHandle const &)> const &visitor) const; // Run custom function for each node.
    size_t getNodesCount() const; // Return count of nodes.
    void forEachEdge(EdgeVisitor const &visitor);

    // Run custom function for each edge.
    NodeHandle move(NodeHandle const &origin, EdgeHandle const &edge); // Move from selected node in selected direction edge. Return ending node.
    NodePayload &operator[](NodeHandle const &node); // Return payload of selected node.
    void dfs(NodeHandle const &startNode, NodeHandle const &endNode, NodeVisitor const &discoverNode); // Run dfs from startNode to endNode and for each visited node runs function discoverNode
private:
    std::vector<NodePayload> nodePayloads;
    std::vector<std::vector<NodeHandle> > graph;
};

template<typename NodePayload>
typename Graph<NodePayload>::NodeHandle Graph<NodePayload>::addNode() {
    NodeHandle nodeHandle = nodePayloads.size() + 1;
    nodePayloads.push_back(0);
    std::vector<NodeHandle> t(nodeHandle);
    graph.push_back(t);
    for (int i = 0; i < nodeHandle; ++i) {
        graph[i].push_back(0);
    }
    return nodeHandle;
}

template<typename NodePayload>
size_t  Graph<NodePayload>::getNodesCount() const {
    return nodePayloads.size();
}

template<typename NodePayload>
NodePayload &Graph<NodePayload>::operator[](Graph::NodeHandle const &node) {
    return nodePayloads[node];
}

template<typename NodePayload>
void Graph<NodePayload>::addEdge(Graph::NodeHandle const &a, Graph::NodeHandle const &b) {
    graph[a][b] = 1;
}

template<typename NodePayload>
void Graph<NodePayload>::forEachNode(std::function<void(NodeHandle const &)> const &visitor) const {
    for (NodeHandle nodeHandle = 0; nodeHandle < getNodesCount(); ++nodeHandle) {
        visitor(nodeHandle);
    }
}

template<typename NodePayload>
void Graph<NodePayload>::forEachEdge(Graph::EdgeVisitor const &visitor) {
    for (unsigned i = 0; i < getNodesCount(); ++i) {
        for (unsigned j = 0; j < getNodesCount(); ++j) {
            if (graph[i][j] == 1) {
                EdgeHandle edgeHandle;
                edgeHandle.first = i,edgeHandle.second = j;
                visitor(edgeHandle);
            }
        }
    }
}

template<typename NodePayload>
void Graph<NodePayload>::dfs(Graph::NodeHandle const &startNode,
        Graph::NodeHandle const &endNode, Graph::NodeVisitor const &discoverNode) {
    for (unsigned i = 0; i < getNodesCount(); ++i) {
        for (unsigned j = 0; j < getNodesCount(); ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    const int IN = 0;
    const int OUT = 1;
    std::vector<int> used(getNodesCount());
    std::stack<std::pair<int, int>> st;
    int n = getNodesCount();
    st.push(std::make_pair(startNode, IN));
    while (!st.empty()) {
        std::pair<int, int> p = st.top();
        st.pop();
        if (p.second == IN) {
            std::cout << "start " << p.first << std::endl;
            std::vector<int> temp;
            st.push(std::make_pair(p.first, OUT));
            for (int i = 0; i < n; ++i) {
                if (graph[p.first][i]) {
                    std::cout << "discover " << i << std::endl;
                    temp.push_back(i);
                }
            }
            for (int i = temp.size() - 1; i >= 0; i--) {
                if (!used[temp[i]])
                    st.push(std::make_pair(temp[i], IN));

            }
        }
        else {
            used[p.first] = OUT;
            std::cout << "end " << p.first << std::endl;
        }
    }

}

template<typename NodePayload>
typename Graph<NodePayload>::NodeHandle Graph<NodePayload>::move(Graph<NodePayload>::NodeHandle const &origin, Graph<NodePayload>::EdgeHandle const &edge) {
    return origin == edge.first ? edge.second : edge.first;
}

#endif