#include "graph.h"

Graph::Graph() {
}

void Graph::addEdge(std::string x, std::string y) {
    this->map[x].push_back(y);
}

void Graph::print(){
    for (auto k : this->map) {
        std::string node = k.first;
        std::list<std::string> ady = k.second;
        std::cout << node << "->";
        for (auto vert : ady) {
            std::cout << vert << ',';
        }
        std::cout << std::endl;
    }
}

void Graph::_dfs(std::string v, std::unordered_set <std::string>&visited) {
    std::list<std::string> ady = this->map[v];
    visited.insert(v);
    for (auto &w : ady) {
        if (visited.find(w) == visited.end()) {
            _dfs(w, visited);
        }
    }
}

bool Graph::dfs() {
    std::unordered_set <std::string> visited;
    _dfs(this->map.begin()->first, visited);
    return visited.size() == this->map.size();
}

bool Graph::dfsDetectCycle() {
    std::unordered_set <std::string> parents;
    std::unordered_set <std::string> visited;
    for (auto &vertex : this->map) {
        if (visited.find(vertex.first) == visited.end()) {
            if (_dfsDetectCycle(vertex.first, parents, visited)) return true;
        }
    }
    return false;
}

bool Graph::_dfsDetectCycle(std::string v, std::unordered_set <std::string> &parents, std::unordered_set <std::string>&visited) {
    std::list<std::string> ady = this->map[v];
    if (visited.find(v) != visited.end()) return false;
    if (parents.find(v) != parents.end()) return true;
    parents.insert(v);
    for (auto &w : ady) {
        if (visited.find(w) == visited.end()) {
            if (_dfsDetectCycle(w, parents, visited)) return true;
        }
    }
    parents.erase(v);
    visited.insert(v);
    return false;
}

Graph::~Graph() {
}
