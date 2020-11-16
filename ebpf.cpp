#include "ebpf.h"

eBPF::eBPF(Results &results, Files &files) :
        results(results), files(files) {}

void eBPF::run() {
    FileParser fileParser;
    std::string buffer;
    std::string fileName;
    while (files.getFileIfExists(fileName)) {
        Digraph graph;
        std::map<std::string, std::vector<std::string>> instructions;
        this->proccessedFile = fileName;
        std::ifstream file(fileName);
        fileParser.getInstructions(buffer, instructions, file);
        for (auto instr : instructions) {
            for (auto &line : instr.second) {
                graph.addEdge(instr.first, line);
           }
        }
        file.close();
        results.addResult(this->proccessedFile,
                        graph.isCyclic(), !graph.isAConnectedGraph());
    }
}

eBPF::~eBPF() {
}
