#include "ebpf.h"

eBPF::eBPF(Results &results, Files &files) :
        results(results), files(files) {}

void eBPF::run() {
    FileParser fileParser(files);
    std::string buffer;
    while (fileParser.areFilesToProcces()) {
        Digraph graph;
        std::map<std::string, std::vector<std::string>> instructions;
        fileParser.getInstructions(buffer, instructions);
        for (auto instr : instructions) {
            for (auto &line : instr.second) {
                graph.addEdge(instr.first, line);
           }
        }
        results.addResult(fileParser.proccessedFile(),
                        graph.isCyclic(), !graph.isAConnectedGraph());
    }
}

eBPF::~eBPF() {
}
