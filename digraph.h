#ifndef __DIGRAPH_H
#define __DIGRAPH_H

#include <iostream>
#include <map>
#include <unordered_set>
#include <list>
#include <string>

class Digraph {
    // Adjacency list implementation
 private:
    std::map <std::string, std::list<std::string>> map;
    bool _isCyclic(std::string v,
                std::unordered_set <std::string> &parents,
                std::unordered_set <std::string>&visited);
    void _isAConnectedGraph(std::string v,
                std::unordered_set <std::string> &visited);
 public:
    Digraph();
    // Adds an edge to the graph, x is the source and y its the destination
    void addEdge(std::string x, std::string y);
    // Applies DFS to the graph and returns true if it is a connected graph
    bool isAConnectedGraph();
    // Applies DFS to the graph and returns true if the graph has a cycle
    bool isCyclic();
    ~Digraph();
};

#endif  // DIGRAPH_H_
