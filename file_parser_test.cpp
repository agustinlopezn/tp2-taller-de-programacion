#include "file_parser.h"
#include "graph.h"

int main() {
    FileParser fileParser("a.bpf");
    Graph g;
    std::string buffer;
    std::map<std::string, std::vector<std::string>> instructions;
    fileParser.getInstructions(instructions, buffer);
    for (auto instr : instructions) {
        for (auto &line : instr.second) {
            g.addEdge(instr.first, line);
            std::cout << instr.first << "->" << line << std::endl;
        }
    }

    if (!g.dfs()) std::cout << "FAIL: unused instructions detected" << std::endl;
    else if (g.dfsDetectCycle()) std::cout << "FAIL: cycle detected" << std::endl;
    else std::cout << "GOOD" << std::endl;

    return 0;
}