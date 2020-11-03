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
    void _dfs(std::string v, std::unordered_set <std::string> &visited);
 public:
    Digraph();
    void addEdge(std::string x, std::string y);
    bool isAConnectedGraph();
    bool isCyclic();
    ~Digraph();
};
