#include "digraph.h"

Digraph::Digraph() {
}

void Digraph::addEdge(std::string x, std::string y) {
    this->map[x].push_back(y);
}

void Digraph::_dfs(std::string v, std::unordered_set <std::string>&visited) {
    std::list<std::string> ady = this->map[v];
    visited.insert(v);
    for (auto &w : ady) {
        if (visited.find(w) == visited.end()) {
            _dfs(w, visited);
        }
    }
}

bool Digraph::isAConnectedGraph() {
    std::unordered_set <std::string> visited;
    _dfs(this->map.begin()->first, visited);
    return visited.size() >= this->map.size();
}

bool Digraph::isCyclic() {
    std::unordered_set <std::string> parents;
    std::unordered_set <std::string> visited;
    for (auto &vertex : this->map) {
        if (visited.find(vertex.first) == visited.end()) {
            if (_isCyclic(vertex.first, parents, visited)) return true;
        }
    }
    return false;
}

bool Digraph::_isCyclic(std::string v,
           std::unordered_set <std::string> &parents,
           std::unordered_set <std::string>&visited) {
    std::list<std::string> ady = this->map[v];
    if (visited.find(v) != visited.end()) return false;
    if (parents.find(v) != parents.end()) return true;
    parents.insert(v);
    for (auto &w : ady) {
        if (visited.find(w) == visited.end()) {
            if (_isCyclic(w, parents, visited)) return true;
        }
    }
    parents.erase(v);
    visited.insert(v);
    return false;
}

Digraph::~Digraph() {
}
