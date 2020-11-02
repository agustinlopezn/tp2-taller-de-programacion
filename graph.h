#include <iostream>
#include <map>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>

class Graph {
    // Adjacency list implementation
 private:
    std::map <std::string, std::list<std::string>> map;
    bool _dfsDetectCycle(std::string v,
                        std::unordered_set <std::string> &parents,
                        std::unordered_set <std::string>&visited);
 public:
    void print();
    Graph();
    void addEdge(std::string x, std::string y);
    bool dfs();
    void _dfs(std::string v, std::unordered_set <std::string>&visited);
    bool dfsDetectCycle();
    ~Graph();
};
